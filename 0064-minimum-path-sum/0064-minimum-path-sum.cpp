class Solution {
public:
// this code give TLE in very large input
    // int minSum(vector<vector<int>>&grid,int m,int n){
    //     if(m<0||n<0)return 1e9;
    //     if(m==0&&n==0)return grid[m][n];

    //     int up = grid[m][n] + minSum(grid,m-1,n);
    //     int left = grid[m][n]+ minSum(grid,m,n-1);
    //     return min(up,left);
    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //      return minSum(grid,m-1,n-1);
    // }

           
    int minSum(vector<vector<int>>&dp,vector<vector<int>>&grid,int i,int j){
        if(i<0||j<0)return 1e9;
        if(i==0&&j==0)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];

        int up = grid[i][j] + minSum(dp,grid,i-1,j);
        int left = grid[i][j]+ minSum(dp,grid,i,j-1);
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
         return minSum(dp,grid,m-1,n-1);
    }

//bottom up approach
    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vector<vector<int>>dp(m,vector<int>(n,-1));
    //      for(int i = 0;i<m;i++){
    //         for(int j = 0;j<n;j++){
    //             if(i==0&&j==0)dp[i][j]=grid[i][j];
    //             else{
    //                 int up=grid[i][j];
    //                 if(i>0)up+=dp[i-1][j];
    //                 else up += 1e9;
    //                 int left = grid[i][j];
    //                 if(j>0)left+=dp[i][j-1];
    //                 else left+=1e9;

    //                 dp[i][j]=min(left,up);
    //             }
    //         }
    //      }
    //      return dp[m-1][n-1];
    // }


};
