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

    unordered_map<Node*,Node*> realToCopy;

    Node* dfsCreateNodes(Node* curr, Node* prev) {

        if (realToCopy.count(curr)) {
            return realToCopy[curr];
        }

        Node* n = new Node(curr->val);
        realToCopy[curr] = n;

        for (Node* nei : curr->neighbors) {
            n->neighbors.push_back(dfsCreateNodes(nei,curr));
        }

        return n;
    }
    Node* cloneGraph(Node* node) {
        if (node != nullptr) {
            return dfsCreateNodes(node,nullptr); 
        }
        return nullptr;
    }
};
