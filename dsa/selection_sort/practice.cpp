#include <iostream>
using namespace std;

// Function to perform Selection Sort on an array
void selectionSort(int arr[], int n) {
  for(int i=0;i<n;i++){
    int minIdx = i;
    for(int j=0;j<n;j++){
        if(arr[j]>arr[minIdx]){
            minIdx = j;
        }
        if(minIdx != i)swap(arr[i],arr[minIdx]);
    }
  }
}

// Function to print array elements
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}