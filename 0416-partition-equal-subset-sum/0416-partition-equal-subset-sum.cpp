class Solution {
public:
int dp[201][10001];
	bool solve(int n, int sum, vector<int>&arr) {
		if (sum == 0)return true;
		if (n == 0)return false; // means we reach till and did'nt get sum==0
		if (dp[n][sum] != -1)return dp[n][sum];
		bool skip = solve(n - 1, sum, arr);
		bool take = false;
		if (arr[n - 1] <= sum) {
			
			take = solve(n - 1, sum - arr[n - 1], arr);
		}
		return dp[n][sum] = take || skip;
		
	}
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;
        return solve(nums.size(), sum/2, nums);
    }
};