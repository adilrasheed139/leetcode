class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // Step 1: Build the adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Step 2: Initialize variables
        int components = 0;
        vector<bool> visited(n, false);

        // Step 3: DFS function
        function<int(int, int)> dfs = [&](int node, int parent) {
            visited[node] = true;
            int sum = values[node];
            
            for (int neighbor : adj[node]) {
                if (neighbor != parent && !visited[neighbor]) {
                    sum += dfs(neighbor, node); // Accumulate the subtree sum
                }
            }
            
            // If the sum of the subtree rooted at this node is divisible by k
            if (sum % k == 0) {
                components++;
                return 0; // Reset sum to 0, as we consider this as a separate component
            }
            
            return sum % k; // Return the remainder to the parent
        };
        
        // Step 4: Start DFS from the root (node 0)
        dfs(0, -1);

        return components;
    }
};
