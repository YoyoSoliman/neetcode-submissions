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
    int count = 0;
    void dfs(TreeNode* curr,int maxValue){

        if (curr==nullptr) {
            return;
        }

        if (curr->val >= maxValue) {
            count++;
        }

        dfs(curr->left, max(curr->val,maxValue));
        dfs(curr->right, max(curr->val,maxValue));



        

    }
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);

        return count;
    }
};
