class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1), rank(n + 1, 0);
        
        // Initialize the parent array where each node is its own parent
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // Function to find the root with path compression
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        };

        // Function to perform union by rank
        auto unionSet = [&](int u, int v) {
            int rootU = find(u);
            int rootV = find(v);
            if (rootU == rootV) return false; // Cycle detected

            // Union by rank
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            return true;
        };

        // Process edges
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (!unionSet(u, v)) {
                return edge; // First edge causing cycle
            }
        }
        return {}; // Should not reach here
    }
};
