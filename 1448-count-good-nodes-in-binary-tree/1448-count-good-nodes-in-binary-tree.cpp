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
    int cnt=0;
    void findSol(TreeNode* root,int &temp){
        if(root==NULL)
            return;
        if(root->left and root->left->val>=temp){
            cnt++;
            int k=temp;
            temp=root->left->val;
            findSol(root->left,temp);
            temp=k;
        }
        else{
            findSol(root->left,temp);
        }
        
        if(root->right and root->right->val>=temp){
            cnt++;
            int k=temp;
            temp=root->right->val;
            findSol(root->right,temp);
            temp=k;
        }
        else{
            findSol(root->right,temp);
        }
    }
    
    int goodNodes(TreeNode* root) {
        int temp=root->val;
        findSol(root,temp);
        return cnt+1;
    }
};