#include <iostream>
using namespace std;
// remove zero in array
#include <iostream>
#include <vector>

// Removes all zeros from arr in-place.
// Returns the new logical size of the array.
int removeZeros(int arr[], int size) {
    int j = 0;  // write index
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[j++] = arr[i];
        }
    }
    return j;  // new size
}
int removeValue(int arr[], int size,int value) {
    int j = 0;  // write index
    for (int i = 0; i < size; i++) {
        if (arr[i] != value) {
            arr[j++] = arr[i];
        }
    }
    return j;  // new size
}
int delByPosition(int arr[], int size,int pos) {
    if(pos< 0 || pos>=size) return size;
    for(int i = pos;i<size-1;i++){
        arr[i] = arr[i+1];
    }
    return size-1;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i =0;i<n;i++)
        cin >> arr[i];
    //int newN = removeZeros(arr,n);
    int del;
    cin >> del;
    int newN = removeValue(arr,n,del);
        
    for(int i =0;i<newN;i++)
        cout << arr[i] << " ";
    cout << endl;
}