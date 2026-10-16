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
    TreeNode* dfs(TreeNode* curr, TreeNode* p, TreeNode* q) {
        if (curr== nullptr) {
            return nullptr;
        }

        if (curr->val < p->val and curr->val < q->val) {
            return dfs(curr->right, p,q);
        } else if (curr->val > p->val and curr->val > q->val) {
            return dfs(curr->left,p,q);
        } else {
            return curr;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
};
