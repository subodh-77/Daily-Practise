class Solution {
public:
    int maximumProduct(vector<int>& nums) {        
        int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int curr : nums) {
            if (curr > first) {
                third = second;
                second = first;
                first = curr;
            } else if (curr > second) {
                third = second;
                second = curr;
            } else if (curr > third) {
                third = curr;
            }
            if (curr < min1) {
                min2 = min1;
                min1 = curr;
            } else if (curr < min2) {
                min2 = curr;
            }
        }
        long long prod1 = (long long)first * second * third;
        long long prod2 = (long long)first * min1 * min2;

        return (int)max(prod1, prod2);
    }
};