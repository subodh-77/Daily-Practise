class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int len = 0;
        int i = 0;
        for(int j = 0;j<s.length();j++){
                mp[s[j]]++;
                while(i<j&&mp[s[j]]>2){
                    mp[s[i]]--;
                    i++;
                }
                 len = max(len,j-i+1);
            
        }
        return len;
    }
};