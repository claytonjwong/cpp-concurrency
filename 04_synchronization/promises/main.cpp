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

void sum(const VI& A, boost::promise<int>& p) {
    p.set_value(std::accumulate(A.begin(), A.end(), 0));
}

int main() {
    boost::promise<VI> gen_promise;
    boost::future<VI> gen_future = gen_promise.get_future();
    boost::thread t1{ gen, std::ref(gen_promise) };

    auto and_then_0 = gen_future.then([](boost::future<VI> gen_future) {
        auto A = gen_future.get();
        std::cout << "A: ", std::copy(A.begin(), A.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout << std::endl;
        return A;
    });

    boost::promise<int> sum_promise;
    boost::future<int> sum_future_0 = sum_promise.get_future();
    boost::thread t2{ sum, and_then_0.get(), std::ref(sum_promise) };
    auto and_then_1 = sum_future_0.then([](boost::future<int> sum_future_1) {
        auto total = sum_future_1.get();
        std::cout << "and_then_1...       " << total << std::endl;
        return total;
    });
    auto and_then_2 = and_then_1.then([](boost::future<int> sum_future_2) {
        auto total = sum_future_2.get() + 100;
        std::cout << "and_then_2...      " << total << std::endl;
        return total;
    });
    auto and_then_3 = and_then_2.then([](boost::future<int> sum_future_3) {
        auto total = sum_future_3.get() + 100;
        std::cout << "and_then_3...      " << total << std::endl;
        return total;
    });

    auto no_more_and_then = and_then_3.get() + 100;
    std::cout << "no_more_and_then!  " << no_more_and_then << std::endl;

    t1.join();
    t2.join();

    return 0;
}
