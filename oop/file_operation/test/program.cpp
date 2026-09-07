#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> ans;
    ofstream file;
    file.open("newdata.txt",ios::app);
    int n = 10;
    for(int i=0;i<n;i++){
        int x;
        cin >>x;
        ans.push_back(x);
    }
    for(int i=0;i<n;i++){
        file << ans[i] << endl;
    }
    file.close();
    return 0;
}