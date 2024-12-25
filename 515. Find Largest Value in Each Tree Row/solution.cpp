class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {}; // If the tree is empty, return an empty vector.

        vector<int> result; // To store the largest values for each row.
        queue<TreeNode*> q; // Queue for BFS traversal.

        q.push(root); // Start with the root node.

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level.
            int maxVal = INT_MIN; // Initialize the maximum value for this level.

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                maxVal = max(maxVal, node->val); // Update maxVal for the level.

                // Add child nodes to the queue.
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(maxVal); // Store the maximum value for this level.
        }

        return result; // Return the result vector.
    }
};
