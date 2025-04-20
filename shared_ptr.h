#pragma once

#include <cstddef>

template <typename T>
class shared_ptr {
private:
    T* ptr_ = nullptr;
    int* count_ = nullptr;

    void cleanup() {
        if (count_) {
            --(*count_);
            if (*count_ == 0) {
                delete ptr_;
                delete count_;
            }
        }
    }

public:
    // TODO: Конструкторы, деструктор, операторы

    shared_ptr() = default;

    explicit shared_ptr(T* ptr) : ptr_(ptr) {
        if (ptr_) {
            count_ = new int(1);
        }
        // TODO: посмотреть, нужно ли что-нибудь в else писать
    }

    // Конструктор копирования
    shared_ptr(const shared_ptr& original) : ptr_(original.ptr_), count_(original.count_) {
        if (count_) {
            ++(*count_);
        }
    }

    shared_ptr& operator=(const shared_ptr& other) {
        if (this == &other) {
            return *this;
        }

        cleanup();

        ptr_ = other.ptr_;
        count_ = other.count_;

        if (count_) {
            ++(*count_);
        }
        return *this;
    }

    ~shared_ptr() {
        cleanup();
    }
}; 