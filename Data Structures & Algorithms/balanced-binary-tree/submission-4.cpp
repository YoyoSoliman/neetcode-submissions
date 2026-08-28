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
    bool res = true;
    int dfs(TreeNode* curr) {
        if (curr == nullptr || res == false) {
            return 0;
        }

        int left = dfs(curr->left) + 1;
        int right = dfs(curr->right) + 1;

        if (abs(left-right) > 1) {
            res = false;
        }

        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);

        return res;
    }
};
