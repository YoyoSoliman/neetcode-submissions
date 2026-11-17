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
    void dfs(TreeNode* curr) {
        if (curr == nullptr) {
            return;
        }

        TreeNode* saved = curr->right;
        curr->right = curr->left;
        curr->left = saved;
        dfs(curr->right);
        dfs(curr->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);

        return root;
    }
};
