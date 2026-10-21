class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        vector<int> prefix(n - 1);
        vector<int> suffix(n - 1);
        
        for (int& x : possible) {
            if (x == 0)
                x = -1;
        }
        prefix[0]=possible[0];
        suffix[n-2]=possible[n-1];
        for (int i = 1; i < n - 1; i++) {

            prefix[i] = possible[i] + prefix[i - 1];
        }
        
        for (int i = n - 3; i >= 0; i--) {

            suffix[i] = possible[i+1] + suffix[i + 1];
        }
      
        for (int i = 0; i < n-1; i++) {
            if (prefix[i] > suffix[i]) {
                return i + 1;
            }
        }
        return -1;
    }
};