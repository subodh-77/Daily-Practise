class Solution {
public:
    int scoreOfString(string s) {
        int sum  = 0;
        for(int i = s.length()-1;i>0;i--){
           int a = s[i];
            int b = s[i-1];
            sum+=abs(a-b);
        }
           return sum;
    }
}; //subodh pathak it goes out of mind