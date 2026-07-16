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
    void inOrder(TreeNode* curr, std::vector<int>& res) {
        if (curr==nullptr) {
            return;
        }

        inOrder(curr->left,res);

        res.push_back(curr->val);

        inOrder(curr->right,res);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        inOrder(root,res);

        return res[k-1];
        
    }
};
