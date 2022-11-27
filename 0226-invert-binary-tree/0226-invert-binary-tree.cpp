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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return root;
        queue<TreeNode*> q1;
        q1.push(root);
        while(q1.size()){
            int n=q1.size();
            for(int i=0;i<n;i++){
                auto it=q1.front();
                q1.pop();
                if(it->left)
                    q1.push(it->left);
                if(it->right)
                    q1.push(it->right);
                swap(it->left,it->right);
            }
        }
        return root;
    }
};