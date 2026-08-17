class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

      
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {

            for (int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                for (int k = l; k < r; k++) {

                    int lSum =
                        prefix[k + 1] - prefix[l];

                    int rSum =
                        prefix[r + 1] - prefix[k + 1];

                    if (lSum < rSum) {

                        dp[l][r] = max(
                            dp[l][r],
                            lSum + dp[l][k]
                        );

                    }
                    else if (lSum > rSum) {

                        dp[l][r] = max(
                            dp[l][r],
                            rSum + dp[k + 1][r]
                        );

                    }
                    else {

                        dp[l][r] = max(
                            dp[l][r],
                            lSum + max(
                                dp[l][k],
                                dp[k + 1][r]
                            )
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};