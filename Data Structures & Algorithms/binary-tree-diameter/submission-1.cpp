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
    int res = 0;

    //returns height
    int dfs(TreeNode* curr) {
        if (curr == nullptr){
            return 0;
        }
        int left = dfs(curr->left);
        int right = dfs(curr->right);

        res = std::max(res, left + right);
        return std::max(left,right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};
