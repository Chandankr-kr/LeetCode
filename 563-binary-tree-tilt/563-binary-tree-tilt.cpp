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
    int res;
    int findSol(TreeNode* root){
        if(!root)
            return 0;
        int left=findSol(root->left);
        int right=findSol(root->right);
        res+=abs(left-right);
        return left+right+root->val;
    }
    int findTilt(TreeNode* root) {
        res=0;
        findSol(root);
        return res;
    }
};