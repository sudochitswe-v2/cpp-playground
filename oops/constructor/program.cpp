#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    // default Constructor
    Person()
    {
        name = "";
        age = 0;
    }
    // parameterized Constructor
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    // default destructor
    ~Person() {}

    void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main()
{
    // Creating an object of Person class
    Person person1("Alice", 30);
    person1.display();

    Person person2("Bob", 25);
    person2.display();

    Person person3;
    person3.display();

    return 0;
}