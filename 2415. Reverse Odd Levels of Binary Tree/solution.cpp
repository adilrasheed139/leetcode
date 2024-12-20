class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;

        // Queue for BFS traversal
        std::queue<TreeNode*> q;
        q.push(root);
        int level = 0; // Root is at level 0

        while (!q.empty()) {
            int size = q.size();
            std::vector<TreeNode*> nodesAtLevel; // Store nodes at current level

            // Collect all nodes at the current level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                nodesAtLevel.push_back(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Reverse node values if the current level is odd
            if (level % 2 == 1) {
                int n = nodesAtLevel.size();
                for (int i = 0; i < n / 2; ++i) {
                    std::swap(nodesAtLevel[i]->val, nodesAtLevel[n - 1 - i]->val);
                }
            }

            ++level; // Move to the next level
        }

        return root;
    }
};