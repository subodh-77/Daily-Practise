class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        vector<int> rank(26);

        // Store position of each character in alien alphabet
        for (int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;
        }

        // Compare every adjacent pair of words
        for (int i = 0; i < words.size() - 1; i++) {

            string w1 = words[i];
            string w2 = words[i + 1];

            int j = 0;
            bool differentFound = false;

            while (j < w1.size() && j < w2.size()) {

                if (w1[j] != w2[j]) {

                    if (rank[w1[j] - 'a'] > rank[w2[j] - 'a']) {
                        return false;
                    }

                    differentFound = true;
                    break;
                }

                j++;
            }

            // Prefix case
            if (!differentFound && w1.size() > w2.size()) {
                return false;
            }
        }

        return true;
    }
};