#include <iostream>

using namespace std;

class A {
    int x;
    public:
        void set(int x){
            this->x = x;
        }
        int get() {
            return this->x;
        }

};
class B : virtual public A { 

};
class C : virtual public A { 

};
// use virtual for common class A
class D : public B, public C {

};

class Car {
    public:
    void func(){
        cout << "Parent" << endl;
    };
};
class Bmw : public Car {
    public:
    void func(){
        cout << "Child" << endl;
    }
};

int main(){

    D obj;
    obj.set(20);
    cout << obj.get() << endl;

    Bmw bmw;
    bmw.Car::func();
    bmw.Bmw::func(); 


    return 0;
}