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
    unordered_map<string,vector<TreeNode*>> mp;
    string findSol(TreeNode* root){
        if(root == NULL)
            return "*";
        string str = "(" + to_string(root->val) + findSol(root->left) + findSol(root->right);
        mp[str].push_back(root);
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        findSol(root);
        vector<TreeNode*> res;
        for(auto it:mp){
            if(it.second.size()>1){
                res.push_back(it.second[0]);
            }
        }
        return res;
    }
};