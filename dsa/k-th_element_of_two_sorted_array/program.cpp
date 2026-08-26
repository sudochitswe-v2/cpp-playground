// GFG question: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array/1
#include <vector>
using namespace std;
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        vector<int> values;
        int i=0;
        int j=0;
        int n=a.size();
        int m=b.size();
        
        while(i<n && j<m){
            if(a[i] < b[j]){
                values.push_back(a[i]);
                i++;
            }
            if(a[i] > b[j]){
                values.push_back(b[i]);
                j++;
            }
        }
        while(i<n){
            a.push_back(a[i]);
            i++;
        }
        while(j<m){
            values.push_back(b[j]);
            j++;
        }
        return values[k-1];
    }
};