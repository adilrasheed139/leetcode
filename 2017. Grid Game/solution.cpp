class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        
        // Compute prefix sums for both rows
        vector<long long> prefix_row_0(n, 0), prefix_row_1(n, 0);
        prefix_row_0[0] = grid[0][0];
        prefix_row_1[0] = grid[1][0];
        
        for (int i = 1; i < n; ++i) {
            prefix_row_0[i] = prefix_row_0[i - 1] + grid[0][i];
            prefix_row_1[i] = prefix_row_1[i - 1] + grid[1][i];
        }
        
        long long result = LLONG_MAX;
        
        for (int i = 0; i < n; ++i) {
            long long top_remaining = prefix_row_0[n - 1] - prefix_row_0[i];
            long long bottom_remaining = (i > 0) ? prefix_row_1[i - 1] : 0;
            
            long long second_robot_points = max(top_remaining, bottom_remaining);
            result = min(result, second_robot_points);
        }
        
        return result;
    }
};
