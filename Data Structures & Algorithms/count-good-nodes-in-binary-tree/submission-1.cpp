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
private:
    int dfs(TreeNode* curr, int m) {
        if (curr == nullptr) {
            return 0;
        }

        if (curr -> val >= m) {
            return dfs(curr->left, curr->val) + dfs(curr->right, curr->val)+ 1;
        } else {
            return dfs(curr->left,m) + dfs(curr->right, m);
        }
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
