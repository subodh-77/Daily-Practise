class Solution {
public:
int dp[101][101];
int solve(int i ,int j ,int m,int n){
    if(i==m-1&&j==n-1){
        return 1;
    }
    int down=0,right =0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(i<m-1){
         down = solve(i+1,j,m,n);
    }
    if(j<n-1){
         right = solve(i,j+1,m,n);
    }
    return dp[i][j]= right + down;

}
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
       return solve(0,0,m,n);
    }
};