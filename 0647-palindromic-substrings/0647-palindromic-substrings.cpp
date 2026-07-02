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
//update is_palin function for further memoization
class Solution {
public:
    bool is_palin(string &s , int i ,int j){
        if(i>j)return true;
        if(s[i]==s[j]) return is_palin(s,i+1,j-1);
        return false;
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
//-------------------------------------------update with memoization
class Solution {
public:
    int dp[1001][1001];
    bool is_palin(string &s , int i ,int j){
        if(i>j)return true;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]) return dp[i][j]=is_palin(s,i+1,j-1);
        return  dp[i][j]=false;
    }
    int countSubstrings(string s) {
        memset(dp,-1,sizeof(dp));
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
