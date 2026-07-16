class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixgcd(n);
        int mx = nums[0];
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixgcd[i] = gcd(nums[i], mx);
        }
        sort(prefixgcd.begin(), prefixgcd.end());
        vector<int> sumgcd;
        int i = 0;
        int j = n - 1;
        long long ans = 0;
        while (i < j) {
            ans += gcd(prefixgcd[i], prefixgcd[j]);
            i++;
            j--;
        }

        return ans;
    }
};