class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,vector<int>&piles){
        if(i>j)return 0;
        if(i==j)return piles[i];
        if(dp[i][j]!=-1)return dp[i][j];
        int pick_i = piles[i]+min(solve(i+2,j,piles),solve(i+1,j-1,piles));
        int pick_j = piles[j]+min(solve(i+1,j-1,piles),solve(i,j-2,piles));

        return dp[i][j]=max(pick_i,pick_j);
        
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
       return solve(0,piles.size()-1,piles)>0;;
    }
};