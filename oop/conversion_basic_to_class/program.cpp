#include <iostream>
using namespace std;

class Number {
    int x;
    public:
    Number(int n){
        x = n;
    }
    void display(){
        cout << "Value = " << x << endl;
    }
};
 // Unit 4 
int main(){

    int a = 10;
    Number obj = a;
    obj.display();

    return 0;
}

