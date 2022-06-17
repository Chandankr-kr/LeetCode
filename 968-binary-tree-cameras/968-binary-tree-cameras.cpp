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
    int count;
    int dfs(TreeNode * root)
    {
        if(!root)
            return 1;
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(left==-1 || right==-1)
        {
            count++;
            return 0;
        }
        if(left==0 || right==0)
            return 1;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        count=0;
        if(dfs(root)==-1)
            count++;
        return count;
    }
};