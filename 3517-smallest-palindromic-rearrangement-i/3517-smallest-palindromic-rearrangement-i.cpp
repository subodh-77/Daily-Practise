class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        if (n == 1)
            return s;
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            freq[ch - 'a']++;
        }
        string left;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            left +=
                string(freq[ch - 'a'] / 2, ch); // generate string (5,a)-->aaaaa
        }
        string right = left;
        reverse(right.begin(), right.end());
        string mid="";
        for (char ch = 'a'; ch <= 'z'; ch++) {
    if (freq[ch - 'a'] % 2) {
        mid += ch;
        break;
    }
}

        return left + mid + right;
    }
};