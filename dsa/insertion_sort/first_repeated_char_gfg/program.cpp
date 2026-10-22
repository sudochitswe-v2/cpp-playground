class Solution {
  public:
    string firstRepChar(string s) {
        int n = s.length();
        string res = "";
        map<char,int> values;
        for(int i=0;i<n;i++){
           if(values.find(s[i])==values.end()){
               values[s[i]]++;
           }else
            values[s[i]]++;
            if(values[s[i]]==2){
                res.push_back(s[i]);
                return res;
            }
        }
        return "-1";
        
    }
};