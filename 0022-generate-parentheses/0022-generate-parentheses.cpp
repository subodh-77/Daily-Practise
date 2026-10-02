class Solution {
public:
    void solve(int open, int close, string output, vector<string>& v) {
        if (open == 0 && close == 0) {
            v.push_back(output);
            return;
        }
        if (open > 0) {
            solve(open - 1, close, output + '(', v);
        }
        if (close > open) {
            solve(open, close - 1, output + ')', v);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        solve(n, n, "", v); // use empty string as initial output
        return v;
    }
};
