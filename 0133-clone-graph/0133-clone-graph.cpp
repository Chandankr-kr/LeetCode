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
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return node;
        unordered_map<Node*,Node*> mp;
        Node* n1=new Node(node->val);
        mp[node]=n1;
        queue<Node*> q1;
        q1.push(node);
        
        while(q1.size()){
            Node* front = q1.front();
            q1.pop();
            for(auto it: front->neighbors){
                if(mp.find(it)==mp.end()){
                    mp[it]=new Node(it->val);
                    q1.push(it);
                }
                mp[front]->neighbors.push_back(mp[it]);
            }
        }
        return n1;
    }
};














