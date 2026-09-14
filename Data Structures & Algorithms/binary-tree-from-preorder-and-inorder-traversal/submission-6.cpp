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
    unordered_map<int, int> inorder_map;

    TreeNode* buildSubtree(const vector<int>& preorder, const vector<int>& inorder,
                           int pre_start, int pre_end, 
                           int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end) {
            return nullptr;
        }

        int root_val = preorder[pre_start];
        int in_pivot = inorder_map[root_val];
        int left_subtree_size = in_pivot - in_start;

        TreeNode* root = new TreeNode(root_val);

        root->left = buildSubtree(preorder, inorder, 
                                  pre_start + 1, pre_start + left_subtree_size, 
                                  in_start, in_pivot - 1);
                                  
        root->right = buildSubtree(preorder, inorder, 
                                   pre_start + left_subtree_size + 1, pre_end, 
                                   in_pivot + 1, in_end);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }

        return buildSubtree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};