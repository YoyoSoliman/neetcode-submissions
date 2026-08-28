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
    vector<vector<int>> levelOrder(TreeNode* root) {

        std::queue<TreeNode*> q;
        if (root!=nullptr) {
            q.push(root);

        }
        vector<vector<int>> res;

        while (!q.empty()) {
            int qLen = q.size();
            vector<int> curLevel = {};

            for (int i = 0; i < qLen;i++) {
                TreeNode* curr = q.front();
                int val = curr->val;

                if (curr->left != nullptr) {
                    q.push(curr->left);

                }
                if (curr->right != nullptr) {
                    q.push(curr->right);

                }
                q.pop();

                curLevel.push_back(val);
            }
            res.push_back(curLevel);
        }

        return res;
    }
};
