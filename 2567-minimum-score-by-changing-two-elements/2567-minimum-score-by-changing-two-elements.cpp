class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return std::min({nums[n - 1] - nums[2], nums[n - 2] - nums[1], nums[n - 3] - nums[0]});
        //eliminating first //two small element , eliminating first element and last element,///eliminating last two element
        //because min is always zero and always 
    }
};