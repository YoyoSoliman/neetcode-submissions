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
    bool sameTree(TreeNode* currQ,TreeNode* currP) {
        if (currQ == nullptr and currP == nullptr) {
            return true;
        }

        if (currQ == nullptr || currP == nullptr || currP->val != currQ->val) {
            return false;
        }

        return sameTree(currQ->right,currP->right) and sameTree(currQ->left,currP->left);
    }

    bool dfs(TreeNode* curr, TreeNode* subRoot) {
        if (curr == nullptr) {
            return false;
        }

        if (sameTree(curr,subRoot)) {
            return true;
        }

        return dfs(curr->left,subRoot) || dfs(curr->right,subRoot);
    }
     
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root,subRoot);
    }
};
