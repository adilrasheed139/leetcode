class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Initialize the reachability matrix
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        
        // Fill the reachability matrix with direct prerequisites
        for (const auto& pre : prerequisites) {
            reachable[pre[0]][pre[1]] = true;
        }
        
        // Floyd-Warshall algorithm to compute transitive closure
        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
                }
            }
        }
        
        // Answer each query
        vector<bool> result;
        for (const auto& query : queries) {
            result.push_back(reachable[query[0]][query[1]]);
        }
        
        return result;
    }
};
