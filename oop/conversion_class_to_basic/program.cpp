#include <iostream>
using namespace std;

class Number{
    int x;
    public:
    Number(int n){
        x = n;
    }
    operator int(){
        return x;
    }
};

int main(){

    Number obj(20);

    int a = obj;
    cout << "Value = " << a << endl;

    return 0;
}