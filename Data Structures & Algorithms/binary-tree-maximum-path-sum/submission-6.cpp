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
    int res = INT_MIN;
    int dfs(TreeNode* curr) {

        if (curr == nullptr) {
            return 0;
        }

        int takeLeft = max(0,dfs(curr->left));

        int takeRight = max(0,dfs(curr->right));


        int currPath = curr->val + takeLeft + takeRight;

        res = max(res,currPath);

        return curr->val + max(takeLeft,takeRight);


    }
    int maxPathSum(TreeNode* root) {
        dfs(root);

        return res;
    }
};
