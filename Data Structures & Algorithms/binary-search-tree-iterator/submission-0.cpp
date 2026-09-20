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
class BSTIterator {
public:
    vector<int> inOrder;
    int pointerIndex;

    void inOrderDfs(TreeNode* curr) {
        if (curr == nullptr) {
            return;
        }

        inOrderDfs(curr->left);
        inOrder.push_back(curr->val);
        inOrderDfs(curr->right);
    }
    BSTIterator(TreeNode* root) {
        pointerIndex = 0;
        inOrderDfs(root);
    }
    
    int next() {
        int val = inOrder[pointerIndex];
        pointerIndex++;
        return val;
    }
    
    bool hasNext() {
        if (pointerIndex == inOrder.size()) {
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */