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

        TreeNode* tmp = curr->left;
        curr->left = curr->right;
        curr->right = tmp;

        dfs(curr->left);
        dfs(curr->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);

        return root;
    }
};
