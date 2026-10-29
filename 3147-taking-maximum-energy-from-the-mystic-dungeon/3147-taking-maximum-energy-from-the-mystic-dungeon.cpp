class Solution {
public:
int K;
int n;

int solve(vector<int>& energy,int i,vector<int>&dp){
    if(i>=n)return 0;
    if(dp[i]!= INT_MIN)return dp[i];
    return dp[i]=energy[i]+solve(energy,i+K,dp);
}
    int maximumEnergy(vector<int>& energy, int k) {
         n= energy.size();
         K = k;
        vector<int> dp(n, INT_MIN);
         int max_energy = INT_MIN;
        for(int i = 0;i<n;i++){
            max_energy = max(max_energy,solve(energy,i,dp));
        }
    return max_energy;
    }
};
//just copy paste due to cold while comes from dehradun from infoys system engineer drive where i fail in aptitude