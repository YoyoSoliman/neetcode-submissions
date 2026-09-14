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
    void dfs(TreeNode*& curr,int target) {
        if (curr == nullptr) {
            return ;
        }

        dfs(curr->left,target);
        dfs(curr->right,target);

        if (curr->left == nullptr and curr->right == nullptr and curr->val == target) {
            curr=nullptr;
        }

    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* dummy = new TreeNode();
        dummy->left = root;
        dfs(dummy,target);
        return dummy->left;
    }
};