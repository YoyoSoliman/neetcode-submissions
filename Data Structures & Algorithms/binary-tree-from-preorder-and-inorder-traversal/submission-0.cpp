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

/*
in-order traversal: 
    dfs(left)
    make
    dfs(right)


pre-order:
    make
    dfs(left)
    dfs(right)
*/

#include <unordered_map>
#include <vector>

class Solution {
private:
    std::unordered_map<int, int> in_map;

    TreeNode* build(const std::vector<int>& preorder, int preStart, int preEnd,
                    const std::vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = in_map[rootVal];
        int numsLeft = inRoot - inStart; 

        root->left = build(preorder, preStart + 1, preStart + numsLeft, 
                           inorder, inStart, inRoot - 1);
        
        root->right = build(preorder, preStart + numsLeft + 1, preEnd, 
                            inorder, inRoot + 1, inEnd);

        return root;
    }

public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        in_map.clear();
        for (int i = 0; i < inorder.size(); ++i) {
            in_map[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, 
                     inorder, 0, inorder.size() - 1);
    }
};