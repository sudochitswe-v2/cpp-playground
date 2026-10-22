#include <iostream>
#include <new>

using namespace std;

void dynamicMemoryAllocation() {
   cout << "\n--- Dynamic Memory Allocation ---\n";
   int *ptr = new int(50); // dynamically allocate memory for an integer
    cout << "Value: " << *ptr << endl; // output the value stored in the allocated memory
    delete ptr; // free the allocated memory
    ptr = nullptr; // set pointer to nullptr after deletion
    int *arr = new int[3]{10,20,30}; // dynamically allocate memory for an array of integers
    cout << "Array values: ";
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr; // free the allocated array memory
    arr = nullptr; // set pointer to nullptr after deletion
}
// 2. Virtual Destructor 
class Base{
    public:
    virtual ~Base() {
        cout << "Base destructor called" << endl;
    }
    virtual void show() {
        cout << "Base class show function" << endl;
    }
    virtual void display()  = 0;
};
// 6. Abstract Class : Base
// Concrete Class : Derived

class Derived : public Base {
    public:
    ~Derived() {
        cout << "Derived destructor called" << endl;
    }
    void show() override {
        cout << "Derived class show function" << endl;
    }
    void display() override {
        cout << "Pure virtual function implemented in Derived class" << endl;
    }
};
// 3. Compile-Time Polymorphism (Function Overloading)
class Calculator{
    public:
    int add(int a, int b) {
        return a + b;
    }
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

// 5.Dynamic Constructor
class DynamicArray{
    int *arr;
    int size;
    public:
    DynamicArray(int n) : arr(new int[n]), size(n) {
        for (int i = 0; i < size; i++) {
            arr[i] = i + 1; // Initialize array with values 1 to n
        }
    }
    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~DynamicArray() {
        delete[] arr; // Free the dynamically allocated array memory
    }
    DynamicArray(const DynamicArray&) = delete; // Delete copy constructor to prevent shallow copy
    DynamicArray& operator=(const DynamicArray&) = delete; // Delete copy assignment operator to prevent shallow copy  
};

//7. Self-Referential Class
class Node {
public:
    int data;
    Node* next; // Pointer to the next node
    Node(int val) : data(val), next(nullptr) {}
};  


// 10. Memory Leak demostration
void memoryLeakDemo() {
    cout << "\n--- Memory Leak Demonstration ---\n";
    int *leakPtr = new int(100); // dynamically allocate memory
    cout << "Value: " << *leakPtr << endl; // output the value stored in the allocated memory
    // Intentionally not deleting the allocated memory to demonstrate memory leak
    // delete leakPtr; // Uncommenting this line would prevent the memory leak
    // leakPtr = nullptr; // set pointer to nullptr after deletion

}
// 11.AllocationFailure Demonstration
void allocationFailureDemo() {
    cout << "\n--- Allocation Failure Demonstration ---\n";
    int *ptr = new (nothrow) int[100];
    if (!ptr) {
        cout << "Memory allocation failed!" << endl;
    } else {
        cout << "Memory allocation succeeded!" << endl;
        delete[] ptr; // free the allocated memory
        ptr = nullptr; // set pointer to nullptr after deletion
    }
}

int main(){
    dynamicMemoryAllocation();


    cout << "\n--- Compile-Time Polymorphism (Function Overloading) ---\n";
    Calculator calc;
    cout << "Sum of 2 numbers: " << calc.add(5, 10) << endl;
    cout << "Sum of 3 numbers: " << calc.add(5, 10, 15) << endl;

    cout << "\n --- Run-Time Polymorphism (Virtual Functions) ---\n";
    Base *basePtr = new Derived(); // base class pointer pointing to derived class object
    basePtr->show(); // calls Derived's show function
    basePtr->display(); // calls Derived's display function
    delete basePtr; // calls Derived's destructor followed by Base's destructor

    //5. Dynamic Constructor
    cout << "\n--- Dynamic Constructor ---\n";
    DynamicArray dynArr(5); // create a dynamic array of size 5
    dynArr.display(); // display the values in the dynamic array

    // 7. Self-Referential Class
    cout << "\n--- Self-Referential Class ---\n";
    Node *first = new Node(10); // create first node
    Node *second = new Node(20); // create second node
    first->next = second; // link first node to second node
    cout << first->data << " -> " << first->next->data << endl; // output the linked nodes
    delete first; // free the first node
    delete second; // free the second node

    memoryLeakDemo(); // demonstrate memory leak

    allocationFailureDemo(); // demonstrate allocation failure
    
    return 0;

}
