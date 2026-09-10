#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("data.dat", ios::binary); // Open a binary file for writing
    int arr[5] = {1, 2, 3, 4, 5};
    file.write((char*)arr, sizeof(arr)); // Write the array to the binary file
    file.close(); // Close the file after writing

    int arr_read[5];
    ifstream read("data.dat", ios::binary); // Open the binary file for reading
    read.read((char*)arr_read, sizeof(arr_read)); // Read the array from the binary file
    read.close(); // Close the file after reading   
    cout << "Read values from binary file: ";
    for (int i = 0; i < 5; i++) {
        cout << arr_read[i] << " "; // Output the read values
    }
    cout << endl;

    return 0;
}