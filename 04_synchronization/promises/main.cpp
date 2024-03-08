#include <algorithm>
#define BOOST_THREAD_PROVIDES_FUTURE
// #define BOOST_THREAD_PROVIDES_FUTURE_CONTINUATION
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
    auto A = gen_future.get();
    std::cout << "A: ", std::copy(A.begin(), A.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout << std::endl;
    t1.join();

    boost::promise<int> sum_promise;
    boost::future<int> sum_future = sum_promise.get_future();
    boost::thread t2{ sum, A, std::ref(sum_promise) };
    auto total = sum_future.get();
    std::cout << "sum: " << total << std::endl;
    t2.join();

    return 0;
}
