#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorites) {
        int n = favorites.size();
        vector<int> inDegree(n, 0), chainLengths(n, 0);
        vector<bool> visited(n, false);

        // Step 1: Calculate in-degrees for all nodes
        for (int fav : favorites) {
            inDegree[fav]++;
        }

        // Step 2: Perform topological sort to calculate chain lengths
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;

            int next = favorites[node];
            chainLengths[next] = max(chainLengths[next], chainLengths[node] + 1);
            if (--inDegree[next] == 0) {
                q.push(next);
            }
        }

        // Step 3: Process cycles and calculate the result
        int maxCycle = 0, totalChains = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int current = i, cycleLength = 0;

                // Detect and calculate the cycle length
                while (!visited[current]) {
                    visited[current] = true;
                    current = favorites[current];
                    cycleLength++;
                }

                if (cycleLength == 2) {
                    // For mutual pairs, calculate total chains attached
                    totalChains += 2 + chainLengths[i] + chainLengths[favorites[i]];
                } else {
                    // For larger cycles, track the maximum cycle length
                    maxCycle = max(maxCycle, cycleLength);
                }
            }
        }

        // Step 4: Return the maximum of the largest cycle or total chains
        return max(maxCycle, totalChains);
    }
};