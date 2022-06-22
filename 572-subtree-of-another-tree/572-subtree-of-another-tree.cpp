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
    bool findSol(TreeNode* root1,TreeNode* root2){
        if(root1==NULL and root2==NULL)
            return true;
        if((root1==NULL and root2) or (root1 and root2==NULL))
            return false;
        if(root1->val != root2->val)
            return false;
        return findSol(root1->left,root2->left) and findSol(root1->right,root2->right); 
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)
            return false;
        if(findSol(root,subRoot))
            return true;
        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
};