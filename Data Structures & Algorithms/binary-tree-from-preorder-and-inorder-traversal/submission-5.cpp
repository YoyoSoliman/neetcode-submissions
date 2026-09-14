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

    unordered_map<int,int> m;

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,int preOrder_left,int preOrder_right, int inOrder_left, int inOrder_right) {
        if (preOrder_left > preOrder_right || inOrder_left > inOrder_right) {
            return nullptr;
        }
        int in_pivot = m[preorder[preOrder_left]];
        int size_of_left = in_pivot - inOrder_left;

        TreeNode* leftT = dfs(preorder,inorder,preOrder_left + 1,preOrder_left + size_of_left, inOrder_left,in_pivot - 1);
        TreeNode* rightT = dfs(preorder,inorder,preOrder_left + size_of_left + 1,preOrder_right, in_pivot + 1,inOrder_right);

        TreeNode* n = new TreeNode();
        n->val = preorder[preOrder_left];
        n->right = rightT;
        n->left = leftT;

        return n;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size();i++) {
            m[inorder[i]] = i;
        }

        return dfs(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);

    }
};
