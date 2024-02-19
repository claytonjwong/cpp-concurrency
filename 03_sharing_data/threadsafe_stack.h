#include <exception>
#include <memory>
#include <mutex>
#include <vector>

struct empty_stack : std::exception {
    const char* what() const throw() {
        return "stack is empty";
    }
};

template <typename T>
class threadsafe_stack {
    std::vector<T> data;
    mutable std::mutex m;
public:
    threadsafe_stack() = default;
    ~threadsafe_stack() = default;
    threadsafe_stack(const threadsafe_stack& other);
    threadsafe_stack(threadsafe_stack&& other) = delete;
    threadsafe_stack& operator=(const threadsafe_stack&);
    threadsafe_stack& operator=(threadsafe_stack&&) = delete;
    void push(T value);
    std::shared_ptr<T> pop();
    void pop(T& value);
    bool empty() const;
    size_t size() const;
};
template <typename T>
threadsafe_stack<T>::threadsafe_stack(const threadsafe_stack& other) {
    std::lock(m, other.m);
    std::lock_guard<std::mutex> my_lock(m, std::adopt_lock);
    std::lock_guard<std::mutex> other_lock(other.m, std::adopt_lock);
    data = other.data;
}
template <typename T>
threadsafe_stack<T>& threadsafe_stack<T>::operator=(const threadsafe_stack& other) {
    std::lock(m, other.m);
    std::lock_guard<std::mutex> my_lock(m, std::adopt_lock);
    std::lock_guard<std::mutex> other_lock(other.m, std::adopt_lock);
    data = other.data;
    return *this;
}
template <typename T>
void threadsafe_stack<T>::push(T value) {
    std::lock_guard<std::mutex> lock(m);
    data.push_back(std::move(value));
}
template <typename T>
std::shared_ptr<T> threadsafe_stack<T>::pop() {
    std::lock_guard<std::mutex> lock(m);
    if (data.empty())
        throw empty_stack();
    auto result = std::make_shared<T>(data.back());
    data.pop_back();
    return result;
}
template <typename T>
void threadsafe_stack<T>::pop(T& value) {
    std::lock_guard<std::mutex> lock(m);
    if (data.empty())
        throw empty_stack();
    value = data.back();
    data.pop_back();
}
template <typename T>
bool threadsafe_stack<T>::empty() const {
    std::lock_guard<std::mutex> lock(m);
    return data.empty();
}
template <typename T>
size_t threadsafe_stack<T>::size() const {
    return data.size();
}
