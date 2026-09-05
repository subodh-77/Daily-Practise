class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
          int n = nums.size();
        vector<int>left(n);
        vector<int>right(n);
        left[0]= nums[0];
        for(int i = 1;i<n;i++){
            if(left[i-1]<nums[i]){
                left[i]=nums[i];
            }
            else left[i]=left[i-1];
        }
        right[n-1]=nums[n-1];
        for(int i = n-2;i>=0;i--){
            if(nums[i]<right[i+1]){
                right[i]=nums[i];
            }
            else right[i]=right[i+1];
        }

        for(int i = 0;i<n;i++){
            if(left[i]-right[i]<=k){
                cout<<left[i]<<right[i];
                return i;
            }
        }
        return -1;
    }
};