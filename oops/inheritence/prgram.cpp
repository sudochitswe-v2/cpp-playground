#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
class Student : public Person
{
private:
    string school;

public:
    Student(string n, int a, string s) : Person(n, a), school(s) {}
    void display() override
    {
        cout << "Name: " << name << ", Age: " << age << ", School: " << school << endl;
    }
};
class Teacher : public Person
{
private:
    string subject;

public:
    Teacher(string n, int a, string sub) : Person(n, a), subject(sub) {}
    void display() override
    {
        cout << "Name: " << name << ", Age: " << age << ", Subject: " << subject << endl;
    }
};
// multiple inheritance example
class TeachingAssistant : public Student, public Teacher
{
public:
    TeachingAssistant(string n, int a, string s, string sub) : Student(n, a, s), Teacher(n, a, sub) {}
    void display() override
    {
        Student::display();
        Teacher::display();
    }
};
int main()
{
    Person *p1 = new Student("Alice", 20, "XYZ University");
    Person *p2 = new Teacher("Bob", 35, "Mathematics");
    TeachingAssistant *p3 = new TeachingAssistant("Charlie", 25, "XYZ University", "Physics");
    p1->display();
    p2->display();
    p3->display();
    delete p1;
    delete p2;
    delete p3;
    return 0;
}