#include <iostream>

using namespace std;
void printArr(int arr[],int n){
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){

    int n;
    cin >> n;
    int arr[n];


    for(int i=0;i<n;i++)
        cin >> arr[i];

    cout << "Before sorting :";
    printArr(arr,n);

    for(int i=0;i<n;i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    cout << "After sorting : ";
    printArr(arr, n);
    return 0;
}