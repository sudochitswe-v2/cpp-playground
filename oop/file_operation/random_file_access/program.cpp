#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // demeonstrate random file access using seekg and seekp
    ofstream file("data.txt");
    file << "Hello, World!"; // Write to the new position
    ifstream read("data.txt");
    read.seekg(1);
    cout << read.tellg() << endl; // Output the current position
    

    return 0;
}