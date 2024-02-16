#include <iostream>
#include <thread>

using namespace std;

void do_work(int n) {
    for (auto i{ 0 }; i < n; ++i)
        cout << "do_work(" << i << ")" << endl;
}

class thread_guard {
    thread& t;
public:
    explicit thread_guard(thread& t_) : t{ t_ } {}
    ~thread_guard() {
        if (t.joinable())
            t.join();
    }
    thread_guard(const thread_guard&) = delete;
    thread_guard(const thread_guard&&) = delete;
    thread_guard& operator=(const thread_guard&) = delete;
    thread_guard& operator=(const thread_guard&&) = delete;
};

int main() {
    int N = 10;
    thread t(do_work, N);
    thread_guard g(t);
    return 0;
}
