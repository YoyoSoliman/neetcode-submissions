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
    int result = 0;

    void dfs(TreeNode* curr,int& k) {

        if (curr == nullptr || k <= 0) {
            return;
        }

        dfs(curr->left,k);
        k--;

        if (k==0) {
            result = curr->val;
            return;
        }
        dfs(curr->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return result;
    }
};
