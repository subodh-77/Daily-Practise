class Solution {
public:
    int solve(int i ,int j,vector<int>&nums){
        if(i>j)return 0;
        if(i==j)return nums[i];
        int pick_i = nums[i]-solve(i+1,j,nums);
        int pick_j = nums[j]-solve(i,j-1,nums);

        return max(pick_i,pick_j);
    }
    bool predictTheWinner(vector<int>& nums) {
       return solve(0,nums.size()-1,nums)>=0;
    }
};