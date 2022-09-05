/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) { val = _val };
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return {};
        queue<Node*> q1;
        q1.push(root);
        while(q1.size()){
            int n=q1.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                Node* t1 = q1.front();
                q1.pop();
                temp.push_back(t1->val);
                for(auto &it:t1->children){
                    if(it){
                        q1.push(it);
                    }
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};