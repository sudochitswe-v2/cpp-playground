// GFG question: https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    bool check(vector<int> &arr,int start, int target){
        int i = start;
        int high = arr.size() - 1;
        while(i <= high){
            int mid = (i + high) /2;
            if(arr[mid] == target)
                return true;
            if(arr[mid]<target)
                i = mid + 1;
            else 
                high = mid - 1;
        }
        return false;
    }
    bool findPair(vector<int> &arr, int x) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for(int i=0;i<n;i++){
            int target = x + arr[i];
            if(check(arr,i+1,target))
                return true;
            else 
                return false;
        }
        return false;
    }
};
