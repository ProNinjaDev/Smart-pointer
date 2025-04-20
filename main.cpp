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
    shared_ptr<MyClass> ptrOrig(new MyClass(10));
    {
        std::cout << "Entering inner scope for copy..." << std::endl;
        shared_ptr<MyClass> ptrCopy = ptrOrig;
        std::cout << "ptrCopy created." << std::endl;
    }
    std::cout << "Inner scope exited. Myclass 10 should still exist" << std::endl;

    std::cout << "\nTest 5: Copy Assignment" << std::endl;
    shared_ptr<MyClass> ptrA(new MyClass(11));
    shared_ptr<MyClass> ptrB(new MyClass(12));
    std::cout << "Assigning ptrA = ptrB" << std::endl;
    ptrA = ptrB;
    std::cout << "Assignment done. Myclass 11 should be deleted" << std::endl;


    std::cout << "\nTest 6: Self-Assignment" << std::endl;
    shared_ptr<MyClass> ptrSelf(new MyClass(13));
    std::cout << "Assigning ptrSelf = ptrSelf" << std::endl;
    ptrSelf = ptrSelf;
    std::cout << "Self-assignment done nothing should crash" << std::endl;


    std::cout << "\nTest 7: Assigning Null" << std::endl;
    shared_ptr<MyClass> ptrToNull(new MyClass(14));
    shared_ptr<MyClass> ptrIsNull;
    std::cout << "Assigning ptrToNull = ptrIsNull" << std::endl;
    ptrToNull = ptrIsNull;
    std::cout << "Assigning null done. Myclass 14 should be deleted" << std::endl;
    std::cout << "\nAll tests passed" << std::endl;


    std::cout << "\nTest 8: Operators *, ->, bool" << std::endl;
    shared_ptr<MyClass> ptrOps(new MyClass(20));

    if (ptrOps) { 
        std::cout << "ptrOps is not null" << std::endl;
        std::cout << "Accessing id via ->: " << ptrOps->id << std::endl;
        std::cout << "Accessing id via *: " << (*ptrOps).id << std::endl;
        (*ptrOps).id = 21;
        std::cout << "Accessing modified id via ->: " << ptrOps->id << std::endl; 
    } else {
        std::cout << "ptrOps is null!" << std::endl;
    }

    shared_ptr<MyClass> ptrNullCheck;
    if (ptrNullCheck) {
        std::cout << "ptrNullCheck is not null!" << std::endl;
    } else {
        std::cout << "ptrNullCheck is correctly null" << std::endl;
    }

    std::cout << "\nEnd of operator tests" << std::endl;

    return 0;
} 