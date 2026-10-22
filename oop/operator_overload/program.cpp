#include <iostream>
using namespace std;
class Complex{
    int real,imaginary;
    public:
    Complex(int real,int imaginary){
        this->real = real;
        this->imaginary = imaginary;
    }
    Complex operator+(Complex c){
        Complex temp(0,0);
        // cout << "real:" << c.real << "img:" << imaginary << endl;
        // cout << "temp real:" << temp.real << "tmep img:" << temp.imaginary << endl;
        temp.real = real + c.real;
        temp.imaginary = imaginary + c.imaginary;
        return temp;
    }
    void display(){
        cout << real << " + " << imaginary << "i" << endl;
    }
};
// Unit 4
int main(){

    Complex c1(10,20);
    Complex c2(5,15);
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}

