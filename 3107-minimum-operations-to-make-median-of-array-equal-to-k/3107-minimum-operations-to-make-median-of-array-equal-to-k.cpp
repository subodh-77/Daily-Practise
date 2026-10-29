class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int m = n / 2;
        long long ans = 0;

        if (nums[m] < k) {
            for (int i = m; i < n; i++) {
                if (nums[i] < k)
                    ans += (long long)(k - nums[i]);
            }
        } else {
            for (int i = 0; i <= m; i++) {
                if (nums[i] > k)
                    ans += (long long)(nums[i] - k);
            }
        }

        return ans;
    }
};