class Solution {
public:
    int countWays(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            if (end >= start2) {
                end = max(end2, end);
            } else {
                ans.push_back({start, end});
                start = start2; //->updating start to next interation start
                end = end2;     //-->
            }
        }
        ans.push_back({start, end});
        int p = ans.size();
        long long res = 1;
        long long MOD = 1e9 + 7;
        for (int i = 0; i < p; i++) {
            res = (res * 2) % MOD;
        }
        return res;
    }
};