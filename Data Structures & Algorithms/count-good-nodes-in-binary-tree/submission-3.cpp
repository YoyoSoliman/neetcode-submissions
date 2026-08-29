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
    int count = 0;
    void dfs(TreeNode* curr, int maxSeen) {
        if (curr == nullptr) {
            return;
        }

        if (curr->val >= maxSeen) {
            count++;
            dfs(curr->left,curr->val);
            dfs(curr->right,curr->val);
        } else {
            dfs(curr->left,maxSeen);
            dfs(curr->right,maxSeen);
        }
    }
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return count;
    }
};
