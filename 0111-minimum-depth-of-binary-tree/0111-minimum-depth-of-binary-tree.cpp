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
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int res=0;
        queue<TreeNode*> q1;
        q1.push(root);
        while(q1.size()){
            int k=q1.size();
            res++;
            
            for(int i=0;i<k;i++){
                TreeNode* temp=q1.front();
                q1.pop();
                if(temp->left){
                q1.push(temp->left);
                }
                if(temp->right){
                q1.push(temp->right);
                }
                 if(temp->left==NULL and temp->right==NULL)
                return res;
            }
            
           
        }
        return 0;
    }
};