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
    bool valid(TreeNode* curr, long long leftBound,long long rightBound) {
        if (curr == nullptr){
            return true;
        }

        if (curr->val >= rightBound || curr->val <= leftBound) {
            return false;
        }

        return valid(curr->left, leftBound, curr->val) && valid(curr->right, curr->val, rightBound);
    }

public:
    bool isValidBST(TreeNode* root) {
        return valid(root,LLONG_MIN,LLONG_MAX);
    }
};
