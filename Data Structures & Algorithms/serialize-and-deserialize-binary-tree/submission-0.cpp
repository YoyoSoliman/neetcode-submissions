#include <sstream>
#include <vector>
#include <string>
using namespace std;

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

class Codec {
public:



    vector<string> split(const string& str) {
        vector<string> tokens;
        stringstream ss(str);
        string token;
    
        while (getline(ss, token, ',')) {
            if (!token.empty()) {
                tokens.push_back(token);
            }
        }
    
        return tokens;
    }

    string res = "";
    // Encodes a tree to a single string.
    void dfsSerialization(TreeNode* curr) {
        if (curr == nullptr) {
            res +="n,";
            return;
        }

        res += to_string(curr->val);
        res+=",";

        dfsSerialization(curr->left);
        dfsSerialization(curr->right);


    }
    string serialize(TreeNode* root) {
        dfsSerialization(root);
        return res;
    }
    
    int index = 0;
    TreeNode* dfsDeserialize(const vector<string>& d) {

        if (index >= d.size()) {
            return nullptr;
        }

        if (d[index] == "n") {
            index++;
            return nullptr;
        }

        TreeNode* n = new TreeNode(stoi(d[index]));
        index++;

        n->left = dfsDeserialize(d);
        n->right = dfsDeserialize(d);


        return n;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> d = split(data);
        return dfsDeserialize(d);
    }
};
