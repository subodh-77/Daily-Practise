class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_e = INT_MAX;
        int min_o = INT_MAX;
        for(int x:nums1){
            if(x%2==0){
                min_e = min(min_e,x);
            }
            else{
                min_o = min(min_o,x);
            }
        }
        if(min_o==INT_MAX){   //ALL EVEN
            return true;
        }
        return min_e>min_o;//to make all odd minimum number should be even
    }
};