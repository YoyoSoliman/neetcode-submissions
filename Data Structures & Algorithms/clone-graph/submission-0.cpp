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
    std::unordered_map<Node*,Node*> oldToNew;

    Node* cloneGraph(Node* node) {
        if (node == nullptr){
            return nullptr;
        }
        dfs(node);
        return oldToNew[node];
    }

    Node* dfs(Node* curr) {

        if (oldToNew.contains(curr)) {
            return oldToNew[curr];
        }

        Node* copy = new Node(curr->val);

        oldToNew[curr] = copy;

        for (Node* nei : curr->neighbors) {
            copy->neighbors.push_back(dfs(nei));
        }

        return copy;


    }
};
