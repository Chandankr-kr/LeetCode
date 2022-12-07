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
    void findSol(TreeNode* root,vector<int>& res){
        if(root==NULL){
            return;
        }
        
        findSol(root->left,res);
        res.push_back(root->val);
        findSol(root->right,res);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> res;
        int sum=0;
        findSol(root,res);
        
        for(int i=0;i<res.size();i++){
            if(res[i]>=low and res[i]<=high){
                sum+=res[i];
            }
        }
        return sum;
    }
};