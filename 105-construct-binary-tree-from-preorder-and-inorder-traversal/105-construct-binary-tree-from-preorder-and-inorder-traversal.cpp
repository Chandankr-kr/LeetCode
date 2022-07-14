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
    TreeNode* findSol(vector<int>& preorder,vector<int>& inorder,int &root,int left,int right){
        if(left>right)
            return NULL;
        int ind=left;
        while(inorder[ind]!=preorder[root])
            ind++;
        root++;
        TreeNode* res=new TreeNode(inorder[ind]);
        res->left=findSol(preorder,inorder,root,left,ind-1);
        res->right=findSol(preorder,inorder,root,ind+1,right);
        return res;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int root=0;
        return findSol(preorder,inorder,root,0,n-1);
    }
};