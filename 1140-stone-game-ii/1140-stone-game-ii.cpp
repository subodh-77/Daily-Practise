class Solution {
public:
    int n;
    int dp[101][101][2];

    int solveforAlice(vector<int>& piles, int i, int person, int M) {
        if (i >= n) return 0;
        if (dp[i][M][person] != -1) return dp[i][M][person];

        int result = (person == 1) ? -1 : INT_MAX;
        int stones = 0;

        for (int x = 1; x <= min(2 * M, n - i); x++) {
            stones += piles[i + x - 1];

            if (person == 1) { 
                result = max(result, stones + solveforAlice(piles, i + x, 0, max(M, x)));
            } else { 
                result = min(result, solveforAlice(piles, i + x, 1, max(M, x)));
            }
        }

        return dp[i][M][person] = result;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        return solveforAlice(piles, 0, 1, 1);
    }
};