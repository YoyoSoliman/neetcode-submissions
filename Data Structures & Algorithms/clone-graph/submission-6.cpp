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
    unordered_map<Node*,Node*> real_to_copy;

    Node* dfs(Node* curr) {
        if (real_to_copy.count(curr)) {
            return real_to_copy[curr];
        }

        Node* n = new Node(curr->val);

        real_to_copy[curr] = n;

        for (Node* nei : curr->neighbors) {
            Node* neig = dfs(nei);
            n->neighbors.push_back(neig);
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
