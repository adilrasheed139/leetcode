class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        
        // Build adjacency list
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<int> color(n + 1, 0); // 0: unvisited, 1: color1, -1: color2
        vector<int> component; // Store nodes of the current component
        
        function<bool(int, int)> isBipartite = [&](int node, int c) {
            queue<int> q;
            q.push(node);
            color[node] = c;
            component.push_back(node);
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : graph[u]) {
                    if (color[v] == 0) {
                        color[v] = -color[u];
                        q.push(v);
                        component.push_back(v);
                    } else if (color[v] == color[u]) {
                        return false; // Found an odd-length cycle
                    }
                }
            }
            return true;
        };

        auto bfsMaxDepth = [&](int start) {
            queue<int> q;
            vector<int> dist(n + 1, -1);
            q.push(start);
            dist[start] = 0;
            int maxDepth = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                maxDepth = max(maxDepth, dist[node]);
                
                for (int neighbor : graph[node]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[node] + 1;
                        q.push(neighbor);
                    }
                }
            }
            return maxDepth + 1; // Depth is 0-based, so add 1
        };

        int maxGroups = 0;

        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                component.clear();
                if (!isBipartite(i, 1)) return -1; // If component is not bipartite, return -1
                
                int maxDepth = 0;
                for (int node : component) {
                    maxDepth = max(maxDepth, bfsMaxDepth(node));
                }
                maxGroups += maxDepth;
            }
        }

        return maxGroups;
    }
};
