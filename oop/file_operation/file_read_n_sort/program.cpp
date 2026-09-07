#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{

    // read unsorted.txt file and store the numbers in a vector
    // sort the numbers in ascending order
    // write the sorted numbers to sorted.txt file
    ifstream inFile("unsorted.txt");
    if (!inFile)
    {
        cerr << "Unable to open file unsorted.txt" << endl;
        return 1;
    }
    vector<int> numbers;
    int number;
    while (inFile >> number)
    {
        numbers.push_back(number);
    }
    inFile.close();
    // use selection sort to sort the numbers in ascending order
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[j] < numbers[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(numbers[i], numbers[minIndex]);
        }
    }
    // write the sorted numbers to sorted.txt file
    ofstream outFile("sorted.txt");
    if (!outFile)
    {
        cerr << "Unable to open file sorted.txt" << endl;
        return 1;
    }
    for (int i = 0; i < numbers.size(); i++)
    {
        outFile << numbers[i] << " ";
    }
    outFile.close();
    return 0;
}