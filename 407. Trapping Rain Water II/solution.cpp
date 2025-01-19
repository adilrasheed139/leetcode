#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;

        int m = heightMap.size();
        int n = heightMap[0].size();

        // Min-heap to store cells with their heights
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Add all boundary cells to the heap
        for (int i = 0; i < m; i++) {
            for (int j : {0, n - 1}) {
                pq.emplace(heightMap[i][j], i, j);
                visited[i][j] = true;
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i : {0, m - 1}) {
                if (!visited[i][j]) {
                    pq.emplace(heightMap[i][j], i, j);
                    visited[i][j] = true;
                }
            }
        }

        // Directions for moving up, down, left, right
        vector<int> directions = {-1, 0, 1, 0, -1};

        int trappedWater = 0;

        // Process the heap
        while (!pq.empty()) {
            auto [height, x, y] = pq.top();
            pq.pop();

            // Check neighbors
            for (int k = 0; k < 4; k++) {
                int nx = x + directions[k];
                int ny = y + directions[k + 1];

                // Skip invalid or already visited cells
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;

                // Water trapped on this cell
                trappedWater += max(0, height - heightMap[nx][ny]);

                // Update the height to maintain the boundary
                pq.emplace(max(height, heightMap[nx][ny]), nx, ny);
                visited[nx][ny] = true;
            }
        }

        return trappedWater;
    }
};
