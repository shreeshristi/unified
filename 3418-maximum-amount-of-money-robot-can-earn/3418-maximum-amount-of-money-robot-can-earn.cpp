class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0) dp[0][0][1] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k <= 2; k++) {
                    if (i == 0 && j == 0) continue;

                    int val = coins[i][j];

                    int best_prev = INT_MIN;
                    if (i > 0) best_prev = max(best_prev, dp[i-1][j][k]);
                    if (j > 0) best_prev = max(best_prev, dp[i][j-1][k]);

                    if (best_prev != INT_MIN)
                        dp[i][j][k] = max(dp[i][j][k], best_prev + val);

                    if (val < 0 && k > 0) {
                        int best_prev_kminus = INT_MIN;
                        if (i > 0) best_prev_kminus = max(best_prev_kminus, dp[i-1][j][k-1]);
                        if (j > 0) best_prev_kminus = max(best_prev_kminus, dp[i][j-1][k-1]);

                        if (best_prev_kminus != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], best_prev_kminus);
                    }
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};