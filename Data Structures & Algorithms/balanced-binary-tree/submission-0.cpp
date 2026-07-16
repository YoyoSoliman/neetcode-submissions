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
    bool balanced = true;

    //gets the height of the trees
    int dfs(TreeNode* curr) {
        if (curr == nullptr) {
            return 0;
        }

        int left = dfs(curr->left);
        int right = dfs(curr->right);

        if (left - right > 1 || left - right < -1) {
            balanced = false;
        }

        return max(left,right) + 1;

    }
public:
    bool isBalanced(TreeNode* root) {
        balanced = true;
        dfs(root);
        return balanced;

    }
};
