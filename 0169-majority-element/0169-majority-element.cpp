class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = 0;int count = 0;
        for(int i = 0;i<nums.size();i++){
            
            
            if(count==0){
                element = nums[i];
            }
            if(element==nums[i]){
                count++;
            }
            else count--;
        }
        int freq = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==element){
                freq++;
            }
        }
        return freq>nums.size()/2?element:-1;
    }
};