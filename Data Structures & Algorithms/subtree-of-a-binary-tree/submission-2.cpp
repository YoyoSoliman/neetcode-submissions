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
    bool res = false;

    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == nullptr and q == nullptr || res) {
            return true;
        }

        if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);

    }
    void dfs(TreeNode* c,TreeNode* subRoot) {
        if (isSameTree(c,subRoot) || res) {
            res = true;
            return;
        }

        if (c->left!=nullptr) {
            dfs(c->left,subRoot);

        }
        if (c->right != nullptr) {
            dfs(c->right,subRoot);
        }
        return;

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root,subRoot);
        return res;
    }
};
