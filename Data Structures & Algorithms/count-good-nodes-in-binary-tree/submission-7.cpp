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
    int dfs(TreeNode* curr,int maxVal) {
        if (curr == nullptr) {
            return 0;
        }

        int l = dfs(curr->left,max(maxVal,curr->val));
        int r = dfs(curr->right, max(maxVal,curr->val));

        if (curr->val >= maxVal) {
            return l + r + 1;
        } else {
            return l + r;
        }
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
};
