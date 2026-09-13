/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool balanced = true;
    int dfs(TreeNode* curr) {
        if (curr == nullptr || !balanced) {
            return 0;
        }

        int l = dfs(curr->left) + 1;
        int r = dfs(curr->right) + 1;

        if (abs(r-l) > 1) {
            balanced = false;
        }

        return max(r,l);
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);

        return balanced;
    }
};
