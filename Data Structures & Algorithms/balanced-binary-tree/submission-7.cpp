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
        if (!balanced) {
            return 0;
        }
        if (curr == nullptr) {
            return 0;
        }
        int left_h = dfs(curr->left);
        int right_h = dfs(curr->right);

        if (abs(left_h-right_h) > 1) {
            balanced = false;
        }

        return max(left_h,right_h) + 1;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return balanced;
    }
};
