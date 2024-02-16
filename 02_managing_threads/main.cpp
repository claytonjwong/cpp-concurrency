#include <iostream>
#include <sstream>
#include <thread>

using namespace std;

thread::id main_thread_id;
auto is_main_thread = []() { return this_thread::get_id() == main_thread_id; };
void do_work(int n) {
    auto f = [](auto i) {
        ostringstream os;
        auto name = is_main_thread() ? "⭐️ main thread" : "💩 other thread";
        os << name << ": " << this_thread::get_id() << " -> do_work(" << i << ")" << endl;
        return os.str();
    };
    for (auto i{ 0 }; i < n; ++i)
        cout << f(i), flush(cout);
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

class scoped_thread {
    thread t;
public:
    explicit scoped_thread(thread t_) : t{ std::move(t_) } {
        if (!t.joinable())
            throw logic_error("No thread!");
    }
    ~scoped_thread() {
        t.join();
    }
    scoped_thread(const scoped_thread&) = delete;
    scoped_thread(const scoped_thread&&) = delete;
    scoped_thread& operator=(const scoped_thread&) = delete;
    scoped_thread& operator=(const scoped_thread&&) = delete;
};

int main() {
    int N = 10;

    // Listing 2.3: Using RAII to wait for a thread to complete
    thread t(do_work, N);
    thread_guard g(t);

    // Listing 2.6: scoped_thread and example usage
    scoped_thread s(thread(do_work, N));

    return 0;
}
