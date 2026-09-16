class Solution {
public:
    int numberOfSets(int n, int k) {
        const int m = 1e9 + 7;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int segments = 1; segments <= k; segments++) {
            long long prefixSum = 0;

            for (int points = 1; points <= n; points++) {
                if (points >= 2) {
                    prefixSum = (prefixSum + dp[points - 1][segments - 1]) % m;
                }

                dp[points][segments] =
                    (dp[points - 1][segments] + prefixSum) % m;
            }
        }

        return dp[n][k];
    }
};