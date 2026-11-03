class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ']') {
                st.push(string(1, s[i]));
            }
            else {
                string substr = "";
                // Extract characters until '['
                while (st.top() != "[") {
                    substr = st.top() + substr;
                    st.pop();
                }
                st.pop(); // Remove '['
                // Extract the number
                string k = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    k = st.top() + k;
                    st.pop();
                }
                int num = stoi(k);
                // Repeat the substring
                string decoded = "";
                for (int j = 0; j < num; j++) {
                    decoded += substr;
                }
                st.push(decoded);
            }
        }
        // Build final answer
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};