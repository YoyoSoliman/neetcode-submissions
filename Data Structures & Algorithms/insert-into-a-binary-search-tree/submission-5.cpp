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
    void dfs(TreeNode* curr, int val) {
        if (val < curr->val) {
            if (curr->left == nullptr) {
                TreeNode* n = new TreeNode(val);
                curr->left = n;
                return; 
            } else {
                dfs(curr->left,val);
            }
        } else {
            if (curr->right == nullptr) {
                TreeNode* n = new TreeNode(val);
                curr->right = n;
                return; 
            } else {
                dfs(curr->right,val);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* n = new TreeNode(val);
            return n;
        }
        
        dfs(root,val);

        return root;
    }
};