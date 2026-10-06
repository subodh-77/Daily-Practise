class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        vector<int>freq(26,0);
        vector<int>freq2(26,0);
        for(int i = 0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i = 0;i<t.length();i++){
            freq2[t[i]-'a']++;
        }
        for(int i = 0;i<26;i++){
           if(freq2[i]<freq[i]){
            ans += abs(freq2[i]-freq[i]);
           }
        }
        return ans;

    }
};