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
        
    std::queue<TreeNode*> q;
    vector<int> res;

    if (root != nullptr) {
        q.push(root);
    }

    while (!q.empty()) {
        int qLen = q.size();
        vector<int> curLevel = {};
        for (int i = 0;i < qLen;i++) {
            int val = q.front()->val;
            if (q.front()->left != nullptr){
                q.push(q.front()->left);
            }
            if (q.front()->right != nullptr){
                q.push(q.front()->right);
            }
            curLevel.push_back(val);
            q.pop();
        }
        res.push_back(curLevel.back());
    }

    return res;

    }
};
