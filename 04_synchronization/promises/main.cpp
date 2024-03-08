#include <algorithm>
#include <future>
#include <iostream>
#include <numeric>
#include <vector>
#include <thread>

using VI = std::vector<int>;

void gen(std::promise<VI> p) {
    auto N = 10;
    VI A(N);
    std::iota(A.begin(), A.end(), 1);
    p.set_value(A);
}

void sum(const VI& A, std::promise<int> p) {
    p.set_value(std::accumulate(A.begin(), A.end(), 0));
}

int main() {
    std::promise<VI> gen_promise;
    std::future<VI> gen_future = gen_promise.get_future();
    std::thread t1{ gen, std::move(gen_promise) };
    auto A = gen_future.get();
    std::cout << "A: ", std::copy(A.begin(), A.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout << std::endl;
    t1.join();

    std::promise<int> sum_promise;
    std::future<int> sum_future = sum_promise.get_future();
    std::thread t2{ sum, A, std::move(sum_promise) };
    auto total = sum_future.get();
    std::cout << "sum: " << total << std::endl;
    t2.join();

    return 0;
}