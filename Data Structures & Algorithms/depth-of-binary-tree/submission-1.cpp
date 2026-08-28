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
    int dfs(TreeNode* curr) {
        if (curr == nullptr) {
            return 0;
        }

        int left = dfs(curr->left) + 1;
        int right = dfs(curr->right) + 1;

        return max(left,right);

    }
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};
