/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> copyToReal;

    Node* dfs(Node* curr) {
        if (copyToReal.count(curr)) {
            return copyToReal[curr];
        }

        Node* n = new Node(curr->val);
        copyToReal[curr] = n;

        for (Node* nei : curr->neighbors) {
            n->neighbors.push_back(dfs(nei));
        }

        return n;
    }
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        return dfs(node);
    }
};
