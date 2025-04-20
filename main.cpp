#include <iostream>
#include "shared_ptr.h"

struct MyClass {
    int id;
    MyClass(int i) : id(i) {
        std::cout << "MyClass(" << id << ") constructed" << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass(" << id << ") destructed" << std::endl;
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

    std::cout << "\nTest 4: Copy Constructor" << std::endl;
    shared_ptr<MyClass> ptr_orig(new MyClass(10));
    {
        std::cout << "  Entering inner scope for copy..." << std::endl;
        shared_ptr<MyClass> ptr_copy = ptr_orig;
        std::cout << "  ptr_copy created." << std::endl;
    }
    std::cout << "Inner scope exited. Myclass 10 should still exist" << std::endl;

    std::cout << "\nTest 5: Copy Assignment" << std::endl;
    shared_ptr<MyClass> ptr_a(new MyClass(11));
    shared_ptr<MyClass> ptr_b(new MyClass(12));
    std::cout << "  Assigning ptr_a = ptr_b" << std::endl;
    ptr_a = ptr_b;
    std::cout << "  Assignment done. Myclass 11 should be deleted" << std::endl;


    std::cout << "\nTest 6: Self-Assignment" << std::endl;
    shared_ptr<MyClass> ptr_self(new MyClass(13));
    std::cout << "  Assigning ptr_self = ptr_self" << std::endl;
    ptr_self = ptr_self; 
    std::cout << "  Self-assignment done nothing should crash" << std::endl;


    std::cout << "\nTest 7: Assigning Null" << std::endl;
    shared_ptr<MyClass> ptr_to_null(new MyClass(14));
    shared_ptr<MyClass> ptr_is_null;
    std::cout << "  Assigning ptr_to_null = ptr_is_null" << std::endl;
    ptr_to_null = ptr_is_null;
    std::cout << "  Assigning null done. Myclass 14 should be deleted" << std::endl;
    std::cout << "\nAll tests passed" << std::endl;

    return 0;
} 