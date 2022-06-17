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
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> q1;
        q1.push(root);
        while(q1.size()){
            int n=q1.size();
            int temp=INT_MIN;
            for(int i=0;i<n;i++){
                auto front=q1.front();
                q1.pop();
                temp=max(temp,front->val);
                if(front->left)
                    q1.push(front->left);
                if(front->right)
                    q1.push(front->right);
            }
            // if(temp!=INT_MIN)
                res.push_back(temp);
        }
        return res;
    }
};