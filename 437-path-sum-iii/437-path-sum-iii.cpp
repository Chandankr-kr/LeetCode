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
    int res=0;
    int  findSol(TreeNode* root,long target){
        if(root==NULL)
            return 0;
        if(target==root->val){
            res++;
            // cout<<target<<" ";
        }
        findSol(root->left,target-root->val);
        findSol(root->right,target-root->val);
        return res;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return 0;
        findSol(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return res;
    }
};