class Solution {
public:
    int smallestNumber(int n, int t) {
        int product;
        for (int i = n; ; i++) {
             product = 1;
            int digit = 0;
            int temp = i;
            while (temp) {
                 digit = temp % 10;
                product = product * digit;
                temp = temp / 10;
            }
            if (product%t==0)return i;
        }
        return 0;
    }
};