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
    bool isSame = true;
    void dfs(TreeNode* curr1, TreeNode* curr2) {
        if ((curr1 == nullptr && curr2 != nullptr) || (curr2 == nullptr && curr1 != nullptr)) {
            isSame = false;
        }
        if (curr1 != nullptr && curr2 != nullptr) {

            if (curr1->val != curr2->val) {
                isSame = false;
            }

            dfs(curr1->right, curr2->right);
            dfs(curr1->left, curr2->left);
        }
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        isSame = true;
        dfs(p,q);
        return isSame;
    }
};
