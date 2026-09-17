class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans="";

        sort(strs.begin(),strs.end());//these arrange as ["flight","flow","flower"]
        string first = strs[0];
        string last = strs[n-1];
        int minlength = min(first.size(),last.size());
        for(int i = 0;i<minlength;i++){
            if(first[i]!=last[i])break;
            ans+=first[i];
        }
        if(ans.size()==0)return "";
        return ans;

    }
};