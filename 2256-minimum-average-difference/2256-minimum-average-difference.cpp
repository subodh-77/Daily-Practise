class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long left_sum = 0;
        long long right_sum = 0;
        long long average = 0;
        int min_index = INT_MAX;
        long long min_value = INT_MAX;
        long long total_sum = accumulate(nums.begin(),nums.end(),0LL);
        if(total_sum==0)return 0;
        if(n==1)return 0;
        for(int i = 0;i<n;i++){
            left_sum+=nums[i];
            right_sum = total_sum-left_sum;
            if(n-i-1==0&&right_sum==0){
                average = (left_sum/(i+1));
            }
            else{
                 average = abs(left_sum/(i+1) - right_sum/(n-i-1));
            }
            if(average<min_value){
                min_value = average;
                min_index = i;
            }
        }
        return min_index;
    }
};