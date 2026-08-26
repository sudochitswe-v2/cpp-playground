#include <iostream>
#include <string>

using namespace std;
class Animal {
    private:
    int legs;
    string breed;
    string color;
    public:
    void setLegs(int legs){
        this->legs = legs;
    }
    void setBreed(string breed){
        this->breed = breed;
    }
    void setColor(string color){
        this->color = color;
    }
    void detail(){
        cout << "Legs: " << legs << endl;
        cout << "Breed: " << breed << endl;
        cout << "Color: " << color << endl;
    }
    void bark(){
        cout << "woof woof" << endl;
    }
};

int main(){
    Animal dog;
    dog.setLegs(4);
    dog.setColor("Black");
    dog.setBreed("German Shepherd");
    dog.detail();
}