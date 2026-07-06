class Solution {
public:
    void solve(string& s, int i,vector<string>& curr_s,vector<vector<string>> &ans,          vector<vector<bool>>& dp) {
            if(i==s.length()){
                ans.push_back(curr_s);
                return;
            }
            for(int j = i;j<s.length();j++){
                if(dp[i][j]==true){
                    curr_s.push_back(s.substr(i,j-i+1));
                    solve(s,j+1,curr_s,ans,dp);
                    curr_s.pop_back();
                }
            }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            int j = i;
            dp[i][j] = true;
        }

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = L + i - 1;
                if (s[i] == s[j]) {
                    if (L == 2)
                        dp[i][j] = true;
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
            }
        }
        vector<vector<string>> ans;
        vector<string> curr_s;
        solve(s, 0, curr_s, ans, dp);
        return ans;
    }
};