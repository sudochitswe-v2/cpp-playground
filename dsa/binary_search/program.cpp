#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> ary = {0,3,5,6,7,8,9,21,35,69,71,85};
    int target = 69;
    int opt = 0;
    int low = 0;
    int high = ary.size() - 1;

    while(low<high){
        int mid = (low + high) / 2;
        opt++;
        if(ary[mid]==target){
            break;
        }else if(ary[mid]<target)
            low = mid +1;
        else 
            high = mid - 1;
    }

    cout << opt << endl;
    return 0;
}