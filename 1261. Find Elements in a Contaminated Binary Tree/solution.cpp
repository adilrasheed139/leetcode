#include <unordered_set>
using namespace std;

class FindElements {
private:
    unordered_set<int> recoveredValues;

    // DFS to recover the tree and store values
    void recoverTree(TreeNode* node, int val) {
        if (!node) return;
        node->val = val;
        recoveredValues.insert(val);
        recoverTree(node->left, 2 * val + 1);
        recoverTree(node->right, 2 * val + 2);
    }

public:
    FindElements(TreeNode* root) {
        if (root) {
            recoverTree(root, 0); // Start recovery with root = 0
        }
    }
    
    bool find(int target) {
        return recoveredValues.count(target);
    }
};
