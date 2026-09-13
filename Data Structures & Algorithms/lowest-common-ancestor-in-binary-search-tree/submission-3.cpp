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
    TreeNode* dfs(TreeNode* curr, int p, int q) {
        if (curr->val < p and curr->val < q) {
            return dfs(curr->right,p,q);
        } else if (curr->val > p and curr->val > q) {
            return dfs(curr->left,p,q);
        } else {
            return curr;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p->val,q->val);
    }
};
