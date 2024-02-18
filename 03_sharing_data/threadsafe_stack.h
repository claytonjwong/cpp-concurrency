#include <exception>
#include <memory>
#include <mutex>
#include <stack>
#include <iostream>

struct empty_stack : std::exception {
    const char* what() const throw() {
        return "stack is empty";
    }
};

template <typename T>
class threadsafe_stack {
    std::stack<T> data;
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
};
template <typename T>
threadsafe_stack<T>::threadsafe_stack(const threadsafe_stack& other) {
    std::lock_guard<std::mutex> lock(other.m);
    data = other.data;
}
template <typename T>
threadsafe_stack<T>& threadsafe_stack<T>::operator=(const threadsafe_stack& other) {
    std::lock_guard<std::mutex> lock(other.m);
    data = other.data;
    return *this;
}
template <typename T>
void threadsafe_stack<T>::push(T value) {
    std::lock_guard<std::mutex> lock(m);
    data.push(std::move(value));
}
template <typename T>
std::shared_ptr<T> threadsafe_stack<T>::pop() {
    std::lock_guard<std::mutex> lock(m);
    if (data.empty())
        throw empty_stack();
    auto result = std::make_shared<T>(data.top());
    data.pop();
    return result;
}
template <typename T>
void threadsafe_stack<T>::pop(T& value) {
    std::lock_guard<std::mutex> lock(m);
    if (data.empty())
        throw empty_stack();
    value = data.top();
    data.pop();
}
template <typename T>
bool threadsafe_stack<T>::empty() const {
    std::lock_guard<std::mutex> lock(m);
    return data.empty();
}
