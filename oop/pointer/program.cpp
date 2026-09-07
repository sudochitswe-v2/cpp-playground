#include <iostream>

using namespace std;

void typesOfPointer(){
    // types of pointer
    //1. NULL pointer
    void *ptr=NULL; // points to memory doesn't exist.
    //2. dangling pointer refers to a deleted memory
    int x = 10;
    int *ptr2 = &x;
    delete ptr2;
    ptr=nullptr;
    //3. wild pointer (points to any random address)
    int *ptr1;
    *ptr1=258;
}

void typeCastPointer(){
    int a = 25;
    void *ptr = &a;
    cout << * (static_cast<int*>(ptr)) << endl; // type casting 
}
void pointerToPointer(){
    int a = 10;
    int *p1 = &a;
    int **q = &p1;
    cout << p1;
}




int main()
{

    // int a = 25;
    // int *ptr = &a;

    // cout << ptr << endl; // reference 
    // cout << *ptr << endl;// dereference

    typesOfPointer();

    return 0;
}