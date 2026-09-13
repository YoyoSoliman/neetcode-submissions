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

    int res = 0;
    int dfs(TreeNode* curr) {
        if (curr == nullptr) {
            return -1;
        }

        int r = dfs(curr->right) + 1;
        int l = dfs(curr->left) + 1;
        res = max(res,r+l);
        return max(r,l);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int m = dfs(root);

        return res;
        
    }
};
