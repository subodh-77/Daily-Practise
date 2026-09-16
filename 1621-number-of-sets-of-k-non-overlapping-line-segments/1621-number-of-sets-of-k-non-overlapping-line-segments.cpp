// class Solution {
// public:
            // THIS GIVE TLE FOR LAST TEST CASE
// long long M = 1e9 + 7;
// int dp[1001][1001];
// int solve(int n,int k,int i){
//     if(k==0)return 1;
//     if(i>=n)return 0;
//     if(dp[i][k]!=-1){
//         return dp[i][k];
//     }
//     long long skip = solve(n,k,i+1)%M;
//     long long take =0;
    
//     for(int end = i+1;end<n;end++){
//         take=(take + solve(n,k-1,end))%M;//trying all end point
//     }

//     return dp[i][k]=(take + skip)%M;
// }
//     int numberOfSets(int n, int k) {
//         memset(dp,-1,sizeof(dp));
//         return solve(n,k,0);//0 is starting point
//     }
// };
class Solution {
public:
    int M = 1e9 + 7;
    int dp[1001][1001];

    int numberOfSets(int n, int K) {

        for (int i = 0; i <= n; i++) {
            dp[0][i] = (i < n) ? 1 : 0;
        }

        for (int k = 1; k <= K; k++) {

            vector<int> prevRowSum(n + 1, 0);

            //prevRowSum[x] = dp[k-1][x] + dp[k-1][x+1] + ... + dp[k-1][n-1]
            for (int x = n - 1; x >= 0; x--) {
                prevRowSum[x] = (prevRowSum[x + 1] + dp[k - 1][x]) % M;
            }

            for (int i = n - 1; i >= 0; i--) {
                
                int skip = dp[k][i + 1];

                int take = prevRowSum[i+1];
                //dp[k-1][i+1] + dp[k-1][i+2] ...... + dp[k-1][n-1]

                dp[k][i] = (take + skip) % M;
            }
        }

        return dp[K][0];
    }
};