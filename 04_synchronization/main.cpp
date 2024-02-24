#include <chrono>
#include <iostream>
#include <iterator>
#include <sstream>
#include <thread>
#include <vector>
#include "threadsafe_queue.h"

using namespace std::chrono_literals;
using namespace std::this_thread;

using LL = long long;
using ThreadSafe_Queue = threadsafe_queue<LL>;

LL N = 10;
ThreadSafe_Queue q;
auto produce_time = 1s,
     consume_time = 10s;
void producer_thread() {
    auto produce = [=]() {
        std::cout << get_id()
                  << " produce 🔨"
                  << std::endl;
        sleep_for(produce_time);
        std::cout << get_id()
                  << " done 🍺"
                  << std::endl;
    };
    for (auto i{ 0 }; i < N; ++i)
        produce(), q.push(i);
}
void consumer_thread() {
    auto consume = [=]() {
        std::cout << get_id()
                  << " consume 🍔"
                  << std::endl;
        sleep_for(consume_time);
        std::cout << get_id()
                  << " done 🍦"
                  << std::endl;
    };
    while(!q.empty()) {
        LL i;
        q.wait_and_pop(i), consume();
    }
}

int main() {
    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;
    generate_n(back_inserter(producers), N, [&]() mutable { return std::thread{ producer_thread }; });
    generate_n(back_inserter(consumers), N, [&]() mutable { return std::thread{ consumer_thread }; });
    for (auto& thread: producers) thread.join();
    for (auto& thread: consumers) thread.join();
    return 0;
}
