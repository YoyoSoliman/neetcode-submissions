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
    bool dfs(TreeNode* currP, TreeNode* currQ) {
        if (currP == nullptr && currQ == nullptr) {
            return true;
        }

        if (currP == nullptr || currQ == nullptr || currQ->val != currP->val) {
            return false;
        }

        return dfs(currP->right,currQ->right) and dfs(currP->left,currQ->left);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
};
