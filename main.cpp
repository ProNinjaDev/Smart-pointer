#include <iostream>
#include "shared_ptr.h"

struct MyClass {
    int id;
    MyClass(int i) : id(i) {
        std::cout << "MyClass(" << id << ") constructed." << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass(" << id << ") destructed." << std::endl;
    }
};

int main() {
    std::cout << "Test 1" << std::endl;
    {
        shared_ptr<MyClass> smartPtr1(new MyClass(1));
    } 
    std::cout << "Test 1 finished" << std::endl;

    std::cout << "Test 2" << std::endl;
    {
        shared_ptr<int> smartPtr2(new int(42));
    } 
    std::cout << "Test 2 finished" << std::endl;

    std::cout << "Test 3" << std::endl;
    {
        shared_ptr<MyClass> smartPtr3(nullptr);
    } 
    std::cout << "Test 3 finished" << std::endl;

    std::cout << "\nAll tests passed" << std::endl;
    return 0;
} 