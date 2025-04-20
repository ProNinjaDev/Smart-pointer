#pragma once

#include <cstddef>
#include <cassert>
#include <iostream>
#include <cstdlib> // Для std::abort


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

    shared_ptr() = default;

    explicit shared_ptr(T* ptr) : ptr_(ptr) {
        if (ptr_) {
            count_ = new int(1);
        }
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

    // Оператор разыменования
    T& operator*() const {
        if (ptr_ == nullptr) {
            std::cerr << "Attempting to dereference a null shared_ptr!" << std::endl;
            std::abort();
        }
        return *ptr_;
    }

    T* operator->() const {
        if (ptr_ == nullptr) {
            std::cerr << "Attempting to use -> on a null shared_ptr" << std::endl;
            std::abort();
        }
        return ptr_;
    }

    explicit operator bool() const {
        return ptr_ != nullptr;
    }
}; 