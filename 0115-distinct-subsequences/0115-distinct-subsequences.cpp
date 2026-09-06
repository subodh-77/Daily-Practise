// class Solution {
// public:
// int dp[1001][1001];
//     int solve(string s, string t,int i ,int j){
//         if(j==t.length())return 1;//poori string match ho gyi
//         if(i==s.length())return 0;//poori string match nahi ho payi aur s string khatam ho gyi
//         if(dp[i][j]!=-1)return dp[i][j];
//         if(s[i]==t[j]){
//             return dp[i][j] = solve(s,t,i+1,j+1)+solve(s,t,i+1,j);

//         }
//         else{
//             return dp[i][j] = solve(s,t,i+1,j);
//         }
//         return -1;
//     }
//     int numDistinct(string s, string t) {
//         memset(dp,-1,sizeof(dp));
//         return solve(s,t,0,0);

//     }
// };

class Solution {
public:
int dp[1001][1001];
    int solve(string s, string t,int m ,int n){
        if(n==0)return 1;//poori string match ho gyi
        if(m==0)return 0;//poori string match nahi ho payi aur s string khatam ho gyi
        if(dp[m][n]!=-1)return dp[m][n];
        if(s[m-1]==t[n-1]){
            return dp[m][n] = solve(s,t,m-1,n-1)+solve(s,t,m-1,n);

        }
        else{
            return dp[m][n] = solve(s,t,m-1,n);
        }
        return -1;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        int m = s.length();
        int n = t.length();
        return solve(s,t,m,n);

    }
};