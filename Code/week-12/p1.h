#include <deque>
#include <functional>
#include <algorithm>

template <typename T>
class Array {
    std::deque<T> _arr;

public:
    Array() {}

    T& operator[](size_t index);

    size_t size() const {
        return _arr.size();
    }

    void view(const std::function<void(const T&)>& f) {
        for (auto t : _arr) {
            f(t);
        }
    }
};
