class Solution {
public:
    // int missingMultiple(vector<int>& nums, int k) {
    //     sort(nums.begin(),nums.end());
    //     int next_num = k;
    //     for(int i = 0;i<nums.size();i++){
    //        if(next_num==nums[i]){
    //         next_num+=k;
    //        }
    //     }
    //     return next_num;
    // }
     int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int cur = k;
        while (seen.count(cur)) {
            cur += k;
        }

        return cur;
    }

};