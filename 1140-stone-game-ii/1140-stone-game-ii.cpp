class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M) {
        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        // Try taking X piles
        for (int x = 1; x <= 2 * M && i + x <= n; x++) {

            // Stones taken by current player
            int taken = suffix[i] - suffix[i + x];

            // Opponent gets the best they can from remaining piles
            int opponent = solve(i + x, max(M, x));

            // Total stones available from this point
            int total = suffix[i];

            // Current player gets total - opponent
            ans = max(ans, total - opponent);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        // Suffix sum
        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};