class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int sum = 0;
        double avgsum = -1e9;
        while(j<nums.size()){
                sum+=nums[j];
            if(j-i+1==k){
                avgsum = max<double>(avgsum,sum);
                sum-=nums[i];
                
                i++;
            }
           
                j++;
            
        }
        return avgsum/k;
    }
};