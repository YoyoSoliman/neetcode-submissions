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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        // 1. Traverse to find the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node found! 

            // Case 1: Node has no left child (handles 0 children or only right child)
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root; // Good practice in C++
                return temp;
            } 
            // Case 2: Node has no right child (only left child)
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Node has both children
            // Find the inorder successor (smallest in the right subtree)
            TreeNode* curr = root->right;
            while (curr->left != nullptr) {
                curr = curr->left;
            }

            // Replace current node's value with the successor's value
            root->val = curr->val;

            // Delete the old successor from the right subtree
            root->right = deleteNode(root->right, curr->val);
        }
        
        return root;
    }
};