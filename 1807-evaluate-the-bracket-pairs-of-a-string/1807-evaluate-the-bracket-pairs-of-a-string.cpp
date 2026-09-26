class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& it : knowledge) mp[it[0]] = it[1];
        int n = s.length();
        bool open = false;
        string ans = "";
        string key ;
        for(int i = 0;i<n;i++){
            if(s[i]=='('){open= true;key = "";}
            else if(s[i]==')'){
                open = false;
                ans+= (mp.find(key)!=mp.end()) ? mp[key]:"?";
            }
            else if(open){
                key+=s[i];
            }
            else{
                ans += s[i];
            }

        }
        return ans;

    }
};
/*open_idx
close_idx
key = s.substr(open_idx+1,close_idx)-->O(n)
if open_idx>=0 same*/

