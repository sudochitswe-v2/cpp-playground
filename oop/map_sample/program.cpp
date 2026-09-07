#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, string> myMap;

    // Inserting elements into the map
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    // Iterating through the map and printing key-value pairs
    for (const auto& pair : myMap) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    return 0;
}
