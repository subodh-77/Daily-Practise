class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        sum = nums[0];
        for(int i = 1;i<n;i++){
            
            if(nums[i]-nums[i-1]==1){
                sum += nums[i];  
            }
            else break;
        }
    //     sort(nums.begin(),nums.end());
    //     bool found = 0;
    //     for(int i = 0;i<n;i++){
    //         if(nums[i]==sum){found = 1;sum++;}

            
    //     }
    //   return sum;
                //another approach for tc O(n)
    unordered_set<int> st(nums.begin(), nums.end());
        while (st.count(sum)) {
            sum++;
        }
        return sum;

    }
};