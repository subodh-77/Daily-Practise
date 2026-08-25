class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int j = 0;
        int ans  = 0;
        unordered_map<int,int>freq;
        for(int j = 0;j<fruits.size();j++){
            freq[fruits[j]]++;
            while(freq.size()>2){
                freq[fruits[i]]--;
                if(freq[fruits[i]]==0){
                    freq.erase(fruits[i]);
                }
                i++;
        }
         ans = max(ans,j-i+1);
        }
        return ans;
    }
};