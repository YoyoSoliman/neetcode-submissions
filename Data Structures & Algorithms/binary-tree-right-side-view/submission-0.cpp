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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> res;

        if (root == nullptr) {
            return res;
        }

        std::queue<TreeNode*> q;
        q.push(root);

        while (q.size() != 0) {
            int qLen = q.size();
            vector<int> level;
            for (int i = 0; i < qLen; i++) {
                TreeNode* n = q.front();
                q.pop();
                if (n != nullptr) {
                    level.push_back(n->val);
                    q.push(n->left);
                    q.push(n->right);
                }

            }
            if (level.size() != 0) {
                res.push_back(level.back());
            }
        }
        return res;
    }
};
