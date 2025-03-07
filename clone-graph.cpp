//https://neetcode.io/problems/clone-graph


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
    Node* helper(Node* node, map<Node*, Node*> &mNode){
        if(node == NULL)
            return node;

        if(mNode.count(node))
            return mNode[node];
        
        Node* n = new Node(node->val);
        mNode[node] = n;

        for(Node* neibhr : node->neighbors){
            n->neighbors.push_back(helper(neibhr, mNode));
        }
        return n;
    }
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> mNode;
        return helper(node, mNode);
    }
};



// Extra:
// adjList=[[2,3,4,5,6,7,8,9],[1,3,4,5,6,7,8,9],[1,2,4,5,6,7,8,9],[1,2,3,5,6,7,8,9],[1,2,3,4,6,7,8,9],[1,2,3,4,5,7,8,9],[1,2,3,4,5,6,8,9],[1,2,3,4,5,6,7,9],[1,2,3,4,5,6,7,8]]
