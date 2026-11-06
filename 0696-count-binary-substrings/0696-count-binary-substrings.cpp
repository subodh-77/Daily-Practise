class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups;
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                groups.push_back(cnt);
                cnt = 1;
            }
        }
        groups.push_back(cnt);
        int ans = 0;
        for (int i = 0; i < groups.size() - 1; i++) {
            ans += min(groups[i], groups[i + 1]);
        }
        return ans;
    }
};