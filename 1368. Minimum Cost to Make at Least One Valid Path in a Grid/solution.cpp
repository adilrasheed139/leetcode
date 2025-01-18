class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Directions: right, left, down, up
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // Minimum cost array
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq; // {row, col}
        
        // Start at (0, 0) with cost 0
        dq.push_front({0, 0});
        cost[0][0] = 0;
        
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            
            for (int d = 0; d < 4; ++d) {
                int nx = x + directions[d][0];
                int ny = y + directions[d][1];
                
                // Check bounds
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                
                // Calculate new cost
                int newCost = cost[x][y] + (grid[x][y] == d + 1 ? 0 : 1);
                
                // Update cost and push into deque
                if (newCost < cost[nx][ny]) {
                    cost[nx][ny] = newCost;
                    if (grid[x][y] == d + 1) {
                        dq.push_front({nx, ny}); // 0-cost edge
                    } else {
                        dq.push_back({nx, ny}); // 1-cost edge
                    }
                }
            }
        }
        
        return cost[m - 1][n - 1];
    }
};
