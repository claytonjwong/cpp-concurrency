#include <algorithm>
#include <future>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <vector>

template<typename T>
std::list<T> sequential_quick_sort(std::list<T> A) {
    if (A.size() < 2)
        return A;
    std::list<T> res;
    res.splice(res.begin(), A, A.begin());
    auto& pivot = *res.begin();
    auto half = std::partition(A.begin(), A.end(), [=](auto x) { return x < pivot; });
    std::list<T> lo; lo.splice(lo.end(), A, A.begin(), half);
    std::list<T> hi; hi.splice(hi.end(), A, half, A.end());
    res.splice(res.begin(), sequential_quick_sort(std::move(lo)));
    res.splice(res.end(), sequential_quick_sort(std::move(hi)));
    return res;
}

template<typename T>
std::list<T> parallel_quick_sort(std::list<T> A) {
    if (A.size() < 2)
        return A;
    std::list<T> res;
    res.splice(res.begin(), A, A.begin());
    auto& pivot = *res.begin();
    auto half = std::partition(A.begin(), A.end(), [=](auto x) { return x < pivot; });
    std::list<T> lo; lo.splice(lo.end(), A, A.begin(), half);
    std::list<T> hi; hi.splice(hi.end(), A, half, A.end());
    res.splice(res.begin(), std::async(parallel_quick_sort<T>, std::move(lo)).get());
    res.splice(res.end(), std::async(parallel_quick_sort<T>, std::move(hi)).get());
    return res;
}

int main() {
    std::list<int> A{ 5, 7, 3, 4, 1, 9, 2, 8, 10, 6 };
    auto S = parallel_quick_sort(A);
    std::copy(A.begin(), A.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout << std::endl;
    std::copy(S.begin(), S.end(), std::ostream_iterator<int>(std::cout, " ")), std::cout << std::endl;
    // 5 7 3 4 1 9 2 8 10 6
    // 1 2 3 4 5 6 7 8 9 10
    return 0;
}
