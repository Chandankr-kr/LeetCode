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
    void flatten(TreeNode* root) {
        stack<TreeNode*> s1;
        if(root==NULL)
            return;
        s1.push(root);
        while(s1.size())
        {
            auto curr=s1.top();
            s1.pop();
            if(curr->right)
                s1.push(curr->right);
            if(curr->left)
                s1.push(curr->left);
            if(s1.size())
                curr->right=s1.top();
            curr->left=NULL;
        }
    }
};