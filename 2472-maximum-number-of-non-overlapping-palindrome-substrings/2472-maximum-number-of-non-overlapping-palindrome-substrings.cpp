// class Solution {
// public:
// bool ispalin(int i,int j,string s,int k){
//     if(j-i+1<k)return false;
//     while(i<j){
//         if(s[i]!=s[j])return false;
//         i++;j--;

//     }

//     return true;
// }
//     int maxPalindromes(string s, int k) {
//         int n = s.length();
//         int count = 0;
//         if(k==1)return n;
//         for(int i = 0;i<n;i++){
//             for(int j = i+1;j<n;j++){
//                 if(ispalin(i,j,s,k)){
//                     cout<<s.substr(i,j-i+1)<<endl;//for my reference
//                     count++;
//                     i=j+1;
//                 }
//             }

//         }
//         return count;
//     }
// };//from this solution only 49/56 test cases passes becasue my solution just
// count valid non- overlapping substring but not optimally for counting
// optimally i go with recursion and trying all valid combination

class Solution {
public:
    int n;
    // int dp[2001][2001];
    bool isPalin(const string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;j--;
        }
        return true;
    }
    int solve(string& s, int k, int i, int j,vector<vector<int>>&dp) {
        if (i >= n || j >= n)
            return 0;
            if(dp[i][j]!=-1)return dp[i][j];
        if (isPalin(s, i, j)) {
        int take =1 +solve(s, k, j + 1, j + k,dp); // now solve for next non -overlapping substring
            int grow = solve(s, k, i, j + 1,dp);      // also see for more length
            int slide = solve(s, k, i + 1, j + 1,dp); // move both i and j
            return dp[i][j]=max({take, grow, slide});
        }
        // if substring is not palin
        int grow = solve(s, k, i, j + 1,dp);
        int slide = solve(s, k, i + 1, j + 1,dp);
        return dp[i][j]=max({ grow, slide});
    }
    int maxPalindromes(string s, int k) {
        n = s.length();
        if (k == 1)
            return n;
            vector<vector<int>>dp(n,vector<int>(n,-1));
       return solve(s, k, 0, k - 1,dp);
    }
};
