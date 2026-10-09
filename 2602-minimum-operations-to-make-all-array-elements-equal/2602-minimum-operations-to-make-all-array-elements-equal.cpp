class Solution {
public:
vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
int n = nums.size();
sort(nums.begin(), nums.end());
    // Create prefix sum array
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    
    vector<long long> ans;
    for (int q : queries) {
        // Binary search to find the index where q would be inserted
        int idx = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
        
        // Operations for elements smaller than q (increase to q)
        long long leftSum = prefixSum[idx];//idhar pr idx point kr rha ha nums array mein index 2 pr . par mein pichle index pr isiliye nhi gya kyunki prefix sum mein mene 0 index    //pr  zero element ha
        long long leftOps = (long long)q * idx - leftSum;
        
        // Operations for elements larger than q (decrease to q)
        long long rightSum = prefixSum[n] - prefixSum[idx];
        long long rightOps = rightSum - (long long)q * (n - idx);
        
        ans.push_back(leftOps + rightOps);
    }
    
    return ans;
}

};
