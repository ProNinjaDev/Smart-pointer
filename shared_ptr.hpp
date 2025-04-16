#pragma once

#include <cstddef>

template <typename T>
class shared_ptr {
private:
    T* ptr_ = nullptr;
    int* count_ = nullptr;

public:
    // TODO: Конструкторы, деструктор, операторы

    shared_ptr() = default;
}; 