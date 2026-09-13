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
    bool dfs(TreeNode* curr, int minValue,int maxValue) {
        if (curr==nullptr) {
            return true;
        }

        if (curr->val <= minValue || curr->val >= maxValue) {
            return false;
        }

        return dfs(curr->left,minValue,min(maxValue,curr->val)) && dfs(curr->right,max(minValue,curr->val),maxValue);

    }
    bool isValidBST(TreeNode* root) {
       return dfs(root, INT_MIN,INT_MAX);
    }
};
