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
    int m = INT_MIN;
    int dfs(TreeNode* curr) {

        if (curr == nullptr) {
            return 0;
        }

        int leftSum = dfs(curr->left);
        int rightSum = dfs(curr->right);

        if (leftSum < 0) {
            leftSum = 0;
        }

        if (rightSum < 0) {
            rightSum = 0;
        }

        int currNode = curr->val + leftSum + rightSum;

        m = max(currNode,m);

        if (currNode < 0) {
            return 0;
        }

        return curr->val + max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);

        return m;
    }
};
