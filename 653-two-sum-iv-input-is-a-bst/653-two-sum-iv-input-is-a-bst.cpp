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
    vector<int> res;
    void findSol(TreeNode* root){
        if(root==NULL)
            return;
        findSol(root->left);
        res.push_back(root->val);
        findSol(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        findSol(root);
        int i=0,j=res.size()-1;
        while(i<j){
            if(res[i]+res[j]==k)
                return true;
            else if(res[i]+res[j]<k)
                i++;
            else
                j--;
        }
        return false;
    }
};