#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> values;
        for(int i=0;i<n;i++){
            values[nums[i]]++;
        }
        for(auto e:values){
            
            if(e.second > n/2)
                return e.first;
        }
        return 0;
    }
};