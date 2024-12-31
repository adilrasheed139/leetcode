class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Maximum day is 365
        int lastDay = days.back();
        vector<int> dp(lastDay + 1, 0);
        unordered_set<int> travelDays(days.begin(), days.end());

        for (int i = 1; i <= lastDay; ++i) {
            if (travelDays.count(i) == 0) {
                dp[i] = dp[i - 1]; // If it's not a travel day
            } else {
                dp[i] = min({
                    dp[i - 1] + costs[0], // 1-day pass
                    dp[max(0, i - 7)] + costs[1], // 7-day pass
                    dp[max(0, i - 30)] + costs[2] // 30-day pass
                });
            }
        }

        return dp[lastDay];
    }
};
