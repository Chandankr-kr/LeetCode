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
    vector<int> v1;
    void findSol(TreeNode* root){
        if(!root)
            return;
        findSol(root->left);
        v1.push_back(root->val);
        findSol(root->right);
    }
    
    void Solve(TreeNode* root,vector<int>& preSum,int& t){
        if(!root)
            return;
        Solve(root->left,preSum,t);
        root->val=preSum[t++];
        Solve(root->right,preSum,t);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return root;
        findSol(root);
        int n=v1.size();
        vector<int> preSum(n,0);
    
        preSum[n-1]=v1[n-1];
        for(int i=n-2;i>=0;i--){
            preSum[i]=preSum[i+1]+v1[i];
        }
        
        for(int i=0;i<v1.size();i++)
            cout<<preSum[i]<<" ";
        
        int t=0;
        Solve(root,preSum,t);
        return root;
    }
};