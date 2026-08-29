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
    bool dfs(TreeNode* curr, int minVal,int maxVal) {

        if (curr == nullptr) {
            return true;
        }

        if (curr->val <= minVal || curr->val >= maxVal) {
            return false;
        }

        return dfs(curr->left, minVal,min(maxVal,curr->val)) && dfs(curr->right, max(minVal,curr->val), maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,INT_MIN,INT_MAX);
    }   
};
