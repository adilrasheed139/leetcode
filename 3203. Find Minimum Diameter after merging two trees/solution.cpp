class Solution {
public:
    int n;
    pair<int, int> BFS(unordered_map<int, vector<int>>& adj, int source) {
        queue<int> que;
        que.push(source);

        unordered_map<int, bool> visited;
        visited[source] = true;

        int distance = 0;
        int farthestNode = source;

        while (!que.empty()) {
            int size = que.size(); // Current level node count

            while (size--) {
                int curr = que.front();
                que.pop();

                farthestNode = curr;

                for (auto &nbr : adj[curr]) {
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        que.push(nbr);
                    }
                }
            }
            if (!que.empty()) {
                distance++;
            }
        }

        return {farthestNode, distance};
    }

    int findDiameter(unordered_map<int, vector<int>> adj) {
        // Step 1: Find the farthest node from an arbitrary node (e.g., node 0)
        auto [farthestNode, dist] = BFS(adj, 0);

        // Step 2: Find the farthest node from the farthestNode found above
        auto [otherEndNode, diameter] = BFS(adj, farthestNode);

        return diameter;
    }

    unordered_map<int, vector<int>> buildAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = buildAdj(edges1);
        unordered_map<int, vector<int>> adj2 = buildAdj(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int combined = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

        return max({d1, d2, combined});
    }
};