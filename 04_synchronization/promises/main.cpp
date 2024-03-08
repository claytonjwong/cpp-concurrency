#include <algorithm>
#define BOOST_THREAD_PROVIDES_FUTURE
#define BOOST_THREAD_PROVIDES_FUTURE_CONTINUATION
#include <boost/thread.hpp>
#include <boost/thread/future.hpp>
#include <future>
#include <iostream>
#include <numeric>
#include <vector>
#include <thread>

using VI = std::vector<int>;

void gen(boost::promise<VI>& p) {
    auto N = 10;
    VI A(N);
    std::iota(A.begin(), A.end(), 1);
    p.set_value(std::move(A));
}

int main() {
    boost::promise<VI> gen_promise;
    auto gen_future = gen_promise.get_future();
    boost::thread thread{ gen, std::ref(gen_promise) };

    auto and_then = gen_future.then([](auto gen_future) {  // and_then 0
        auto A = gen_future.get();
        std::cout << "A: ", std::copy(A.begin(), A.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout << std::endl;
        return std::accumulate(A.begin(), A.end(), 0);
    }).then([](auto sum_future) {  // and_then_1
        auto total = sum_future.get();
        std::cout << "and_then_1...       " << total << std::endl;
        return total;
    }).then([](auto sum_future) {  // and_then_2
        auto total = sum_future.get() + 100;
        std::cout << "and_then_2...      " << total << std::endl;
        return total;
    }).then([](auto sum_future) {  // and_then_3
        auto total = sum_future.get() + 100;
        std::cout << "and_then_3...      " << total << std::endl;
        return total;
    }).then([](auto sum_future) {  // no_more_and_then
        auto total = sum_future.get() + 100;
        std::cout << "no_more_and_then!  " << total << std::endl;
        return total;
    }).get();

    return 0;
}
