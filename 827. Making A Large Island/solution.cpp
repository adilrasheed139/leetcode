class Solution {
public:
    int n;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int dfs(vector<vector<int>>& grid, int i, int j, int index) {
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) 
            return 0;
        
        grid[i][j] = index; // Mark this cell with the island index
        int size = 1;
        
        for (auto& dir : directions) {
            size += dfs(grid, i + dir[0], j + dir[1], index);
        }
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> islandSize;
        int index = 2, maxSize = 0;
        
        // Step 1: Label islands and store their sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    islandSize[index] = dfs(grid, i, j, index);
                    maxSize = max(maxSize, islandSize[index]); // Track the largest island size
                    index++;
                }
            }
        }

        // Step 2: Try flipping each 0 and merge islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int newSize = 1;
                    
                    for (auto& dir : directions) {
                        int x = i + dir[0], y = j + dir[1];
                        if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] > 1) {
                            seen.insert(grid[x][y]); // Collect unique island indexes
                        }
                    }
                    
                    for (int id : seen) {
                        newSize += islandSize[id]; // Add sizes of connected islands
                    }
                    
                    maxSize = max(maxSize, newSize);
                }
            }
        }

        return maxSize == 0 ? n * n : maxSize;
    }
};
