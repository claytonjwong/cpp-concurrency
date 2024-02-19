#include <iostream>
#include <iterator>
#include <sstream>
#include <thread>
#include <vector>
#include "threadsafe_stack.h"

using LL = long long;
using ThreadSafe_Stack = threadsafe_stack<LL>;

int main() {
    LL N = 10;
    ThreadSafe_Stack orig;
    for (LL i{ 0 }; i < N; ++i)
        orig.push(i);
    auto pop_until_empty = [&](ThreadSafe_Stack& stack, const std::string& name) {
        std::ostringstream os;
        os << "stack size: " << stack.size() << std::endl;
        while (!stack.empty()) {
            auto value = *stack.pop();
            os << name << ": ", fill_n(std::ostream_iterator<char>(os, ""), value, '_'), os << value << std::endl;
        }
        std::cout << os.str(), std::flush(std::cout);
    };
    auto copy_and_pop_until_empty = [&]() {
        threadsafe_stack<LL> copy{ orig };
        std::ostringstream os; os << "🍎 copy (" << copy.size() << ")";
        pop_until_empty(copy, os.str());
    };
    auto deep_and_pop_until_empty = [&]() {
        threadsafe_stack<LL> deep = orig;
        std::cout << deep.size() << std::endl;
        std::ostringstream os; os << "🍊 deep (" << deep.size() << ")";
        pop_until_empty(deep, os.str());
    };

    std::cout << "********** Sequentially **********" << std::endl;
    copy_and_pop_until_empty();
    deep_and_pop_until_empty();

    std::cout << "********** Concurrently **********" << std::endl;
    std::vector<std::thread> A;
    std::vector<std::thread> B;
    generate_n(back_inserter(A), N, [&]() mutable { return std::thread{ copy_and_pop_until_empty }; });
    generate_n(back_inserter(B), N, [&]() mutable { return std::thread{ deep_and_pop_until_empty }; });

    for (auto& thread: A) thread.join();
    for (auto& thread: B) thread.join();

    pop_until_empty(orig, "🍏 orig"); // Main thread work

    return 0;
}
