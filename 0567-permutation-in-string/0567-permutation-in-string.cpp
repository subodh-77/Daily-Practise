class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.length();
        int m = s1.length();
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(auto &it:s1){
            freq1[it-'a']++;
        }

        int i = 0,j = 0;
        while(j<n){
            freq2[s2[j]-'a']++;

             if(j-i+1>m){
                freq2[s2[i]-'a']--;
                i++;}
            if(freq1==freq2)return true;
            j++;
        }
         
        return false;
    }
};