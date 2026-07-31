class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,0);
        for(char &it:word){
            mp[it-'a']++;
        }
        sort(mp.begin(),mp.end(),greater<int>());
        int result = 0;
        for(int i = 0 ;i<26;i++){
            int freq = mp[i];
            int press = i/8 +1;
            result += freq*press;
        }
        return result;
    }
};