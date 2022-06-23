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
        if(!root)
            return;
        res.push_back(root->val);
        findSol(root->left);
        findSol(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        findSol(root);
        int i=0,j=res.size()-1,sum=0;
        sort(res.begin(),res.end());
        while(i<j){
            sum=res[i]+res[j];
            if(sum==k)
                return true;
            if(sum>k)
                j--;
            else
                i++;
        }
        return false;
    }
};