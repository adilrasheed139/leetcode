#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int totalSwaps = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelValues;

            // Collect all values at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Calculate minimum swaps to sort the current level
            totalSwaps += calculateMinSwaps(levelValues);
        }
        
        return totalSwaps;
    }

private:
    int calculateMinSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> valueIndex(n);
        for (int i = 0; i < n; ++i) {
            valueIndex[i] = {arr[i], i};
        }

        // Sort the array by value, keeping track of original indices
        sort(valueIndex.begin(), valueIndex.end());

        // Count cycles in the permutation
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || valueIndex[i].second == i) continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = valueIndex[j].second;
                ++cycleSize;
            }

            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }

        return swaps;
    }
};
