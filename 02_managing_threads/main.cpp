#include <iostream>
#include <sstream>
#include <thread>
#include <vector>

using namespace std;

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

class joining_thread {
    thread t;
    joining_thread& assign(joining_thread&& other) {
        if (joinable())
            join();
        t = std::move(other.t);
        return *this;
    }
public:
    joining_thread() noexcept = default;
    template<typename Callable, typename ...Args>
    explicit joining_thread(Callable&& func, Args&& ...args) : t{ std::forward<Callable>(func), std::forward<Args>(args)... } {}
    explicit joining_thread(thread t_) noexcept : t{ std::move(t_) } {}
    joining_thread(joining_thread& other) = delete;
    joining_thread(joining_thread&& other) noexcept : t{ std::move(other.t) } {}
    joining_thread& operator=(joining_thread other) noexcept { return assign(std::move(other)); }
    joining_thread& operator=(joining_thread& other) = delete;
    joining_thread& operator=(joining_thread&& other) noexcept { return assign(std::move(other)); }
    ~joining_thread() noexcept {
        if (joinable())
            join();
    }
    bool joinable() const noexcept { return t.joinable(); }
    void join() { t.join(); }
    void swap(joining_thread& other) noexcept { t.swap(other.t); }
    thread::id get_id() const noexcept { return t.get_id(); }
    void detach() { t.detach(); }
    thread& as_thread() noexcept { return t; }
    const thread& as_thread() const noexcept { return t; }
};

int main() {
    auto N = 10;
    auto main_thread_id = this_thread::get_id();
    auto do_work = [&](int n) {
        auto f = [&](auto i) {
            ostringstream os;
            auto name = this_thread::get_id() == main_thread_id ? "⭐️ main thread" : "💩 other thread";
            os << name << ": " << this_thread::get_id() << " -> do_work(" << i << ")" << endl;
            return os.str();
        };
        for (auto i{ 0 }; i < n; ++i)
            cout << f(i), flush(cout);
    };

    // Listing 2.3: Using RAII to wait for a thread to complete
    {
        thread t(do_work, N);
        thread_guard g(t);
    }

    // Listing 2.6: scoped_thread and example usage
    {
        scoped_thread s(thread(do_work, N));
    }

    // Lising 2.7 A joining_thread class
    {
        joining_thread j1(thread(do_work, N));
        joining_thread j2(thread(do_work, N));
        auto j3{ std::move(j2) };
    }

    // Listing 2.8 Spawn some threads and wait for them to finish
    vector<thread> A;
    generate_n(back_inserter(A), N, [&]() mutable {
        return thread{ do_work, N };
    });

    // Main thread work
    do_work(N);

    for (auto& it: A)
        it.join();

    return 0;
}
