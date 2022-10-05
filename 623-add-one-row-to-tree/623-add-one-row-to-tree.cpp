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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* res=new TreeNode(val);
            res->left=root;
            return res;
        }
        int cnt=0;
        queue<TreeNode*> q1;
        q1.push(root);
        while(q1.size()){
            int n=q1.size();
            cnt++;
            for(int i=0;i<n;i++){
                auto it=q1.front();
                q1.pop();
                if(cnt!=depth-1){
                    if(it->left)
                        q1.push(it->left);
                    
                    if(it->right)
                        q1.push(it->right);
                }
                else{
                    TreeNode* temp=new TreeNode(val);
                    temp->left=it->left;
                    it->left=temp;
                    
                    TreeNode* temp1=new TreeNode(val);
                    temp1->right=it->right;
                    it->right=temp1;
                }
            }
        }
        return root;
    }
};