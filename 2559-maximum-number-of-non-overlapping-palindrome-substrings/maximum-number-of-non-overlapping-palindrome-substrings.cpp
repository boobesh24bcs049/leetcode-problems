class Solution {
public:
    int maxPalindromes(string s, int k) {
         int n = s.size();

        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int left = 0; left + len <= n; left++) {
                int right = left + len - 1;

                if (s[left] == s[right] &&
                    (len <= 2 || palindrome[left + 1][right - 1])) {
                    palindrome[left][right] = true;
                }
            }
        }

        vector<int> dp(n + 1, 0);

        for (int end = 1; end <= n; end++) {
            dp[end] = dp[end - 1];

            for (int start = 0; start < end; start++) {
                if (end - start >= k && palindrome[start][end - 1]) {
                    dp[end] = max(dp[end], dp[start] + 1);
                }
            }
        }

        return dp[n];
    }
};