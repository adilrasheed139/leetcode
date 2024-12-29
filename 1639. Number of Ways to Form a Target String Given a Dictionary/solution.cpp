class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int m = target.size();
        int n = words[0].size();

        // Step 1: Count frequency of each character at each column
        vector<vector<int>> freq(26, vector<int>(n, 0));
        for (const string& word : words) {
            for (int j = 0; j < n; ++j) {
                freq[word[j] - 'a'][j]++;
            }
        }

        // Step 2: DP table
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;

        // Step 3: Fill DP table
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i < m) {
                    // If target[i] can be formed using column j
                    char c = target[i];
                    dp[i + 1][j + 1] += dp[i][j] * freq[c - 'a'][j];
                    dp[i + 1][j + 1] %= MOD;
                }
                // Transition if we skip column j
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= MOD;
            }
        }

        return dp[m][n];
    }
};
