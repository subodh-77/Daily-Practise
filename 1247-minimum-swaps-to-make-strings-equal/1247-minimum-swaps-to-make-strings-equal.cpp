class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0,yx =0;
        for(int i = 0;i<s1.size();i++){
            if(s1[i]=='x'&&s2[i]=='y')xy++;
            else if(s1[i]=='y'&&s2[i]=='x')yx++;
        }
        if(xy%2!=yx%2)return -1;
        //both xy and yx are odd odd or even even
        // if even nothing left in remainder  
        //but if odd  1 left of xy and 1 left of yx so combine both they require 2 swap
        return xy/2 + yx/2 + (xy%2)*2;// xy/2 
    }
};