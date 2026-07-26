class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        int n= nums.size();
        for(int i= 0;i<n;i++){
            if(i>farthest)return false;//apne element se aage hee nhi jaa paa rha ha kyunki farthest hmesha jayada hona chaiye hmaesha apne index se aage janaa chaiye
            farthest = max(farthest,i+nums[i]);
            if(farthest>=n-1)return true;
        }
        return false;
    }
};