class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());

        int i = 0;
        int n = s.length();
        int l = 0,r = 0;
        while(i<n){
            while(i<n&&s[i]!=' '){//i ko agr character dikhe toh r s[r]  ko assign karega
                s[r++]=s[i++];
            }
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);//l se r tk reverse
                s[r]=' ';//reverse krne ke baad space add krdo
                r++;
                l = r;
            }
            i++;
        }
        return s.substr(0,r-1);
    }
};