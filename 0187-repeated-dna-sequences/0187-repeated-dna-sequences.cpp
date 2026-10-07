class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int>mp;
        int i = 0;
        int j = 9;
        while(j<s.length()){
           mp[s.substr(i,j-i+1)]++;
           i++;j++;
        }
        vector<string>result;
        for(auto it:mp){
            if(it.second>1){
                result.push_back(it.first);
            }
        }
        return result;
    }
};