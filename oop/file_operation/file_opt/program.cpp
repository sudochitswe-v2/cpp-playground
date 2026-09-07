#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void writeToFile(const string &filename, const string &content)
{
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << content;
        outFile.close();
    }
    else
    {
        cerr << "Unable to open file: " << filename << endl;
    }
}

void readFromFile(const string &filename)
{
    ifstream inFile(filename);
    if (inFile.is_open()) ios::out
    {
        // string line;
        // while (getline(inFile, line)) {
        //     cout << line << endl;
        // }
        // inFile.close();

        char c;
        c = inFile.get();
        while (!inFile.eof())
        {
            cout << c;
            c = inFile.get();
        }
    }
    else
    {
        cerr << "Unable to open file: " << filename << endl;
    }
}
void writeToFile(const string &filename, const vector<int> &content)
{
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        for (const auto &line : content)
        {
            outFile << line << " ";
        }
        outFile.close();
    }
    else
    {
        cerr << "Unable to open file: " << filename << endl;
    }
}

void appendToFile(const string &filename, const string &content)
{
    ofstream outFile(filename, ios::app);
    if (outFile.is_open())
    {
        outFile << content;
        outFile.close();
    }
    else
    {
        cerr << "Unable to open file: " << filename << endl;
    }
}
int main()
{
    writeToFile("test.py", "print('Hello, World!')");
    readFromFile("test.py");
    writeToFile("numbers.txt", vector<int>{10, 20, 69, 58});
    appendToFile("test.py", "\nprint('Goodbye, World!')");
    return 0;
}