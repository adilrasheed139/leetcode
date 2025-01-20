class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Map each value in mat to its (row, col) position
        unordered_map<int, pair<int, int>> positionMap;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                positionMap[mat[i][j]] = {i, j};
            }
        }
        
        // Counters for painted cells in each row and column
        vector<int> rowPaintCount(m, 0);
        vector<int> colPaintCount(n, 0);
        
        // Process each value in arr
        for (int i = 0; i < arr.size(); ++i) {
            int value = arr[i];
            auto [row, col] = positionMap[value];
            
            // Increment counters for the corresponding row and column
            rowPaintCount[row]++;
            colPaintCount[col]++;
            
            // Check if the row or column is completely painted
            if (rowPaintCount[row] == n || colPaintCount[col] == m) {
                return i; // Return the current index
            }
        }
        
        return -1; // This should never be reached based on constraints
    }
};
