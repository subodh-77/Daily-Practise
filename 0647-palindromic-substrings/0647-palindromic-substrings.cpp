class Solution {
public:
    bool is_palin(string s , int i ,int j){
        string t = s.substr(i,j-i+1);
        string x = t;
        reverse(x.begin(),x.end());
        return x==t?true:false;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(is_palin(s,i,j))count++;
            }
        }
        return count;
    }
};