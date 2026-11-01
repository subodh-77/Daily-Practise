class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        int ans=0;
        for(auto it:mp){
            if(it.second>=3&&it.second%2==0)ans += it.second-2;
            else if(it.second>=3&&it.second%2!=0)ans += it.second-1;
        }
        return s.length()-ans;
    }
};