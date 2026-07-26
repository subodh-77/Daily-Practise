class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestending = 0;
        int maxsum = INT_MIN;

        for(int i = 0;i<nums.size();i++){
            int choice1 = bestending + nums[i];
            int choice2 = nums[i];
            bestending= max(choice1,choice2);
            maxsum = max(maxsum,bestending);
        }
        return maxsum;
    }
};