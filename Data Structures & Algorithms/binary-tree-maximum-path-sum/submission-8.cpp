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
    int res = 0;
    int dfs(TreeNode* curr) {

        if (curr == nullptr) {
            return 0;
        }

        int takeLeft = dfs(curr->left) + curr->val;
        int takeRight = dfs(curr->right) + curr->val;


        res = max(res, takeLeft+takeRight - curr->val);

        if (takeLeft <= 0 and takeRight <= 0) {
            return 0;
        }

        if (takeLeft < takeRight) {
            return takeRight;
        }

        return takeLeft;

    }
    int maxPathSum(TreeNode* root) {
        res = root->val;
        dfs(root);

        return res;
    }
};
