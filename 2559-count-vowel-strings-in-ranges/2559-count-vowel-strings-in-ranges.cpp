class Solution {
public:
  bool isvowel(string& s) {
    int n = s.size();

    if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' ||
         s[0] == 'o' || s[0] == 'u') &&
        (s[n - 1] == 'a' || s[n - 1] == 'e' ||
         s[n - 1] == 'i' || s[n - 1] == 'o' ||
         s[n - 1] == 'u')) {
        return true;
    }

    return false;
}
    vector<int> vowelStrings(vector<string>& words,vector<vector<int>>& queries) {
int n = words.size();
        vector<int> cum_sum(n);
       
        for (int i = 0; i < n; i++) {
            if (isvowel(words[i])) {
                cum_sum[i] = 1;
            } else {
                cum_sum[i] = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            cum_sum[i] += cum_sum[i - 1];
        }
        vector<int> result(queries.size(),0);
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            if (l == 0) {
                result[i] = cum_sum[r];
            } else {
                result[i] = cum_sum[r] - cum_sum[l - 1];
            }
        }
        return result;
    }
};