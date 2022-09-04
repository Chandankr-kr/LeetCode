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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q1;
        q1.push({root,{0,0}});
        while(q1.size()){
            
            
            TreeNode* temp=q1.front().first;
            int x=q1.front().second.first;
            int y=q1.front().second.second;
            q1.pop();
            mp[x][y].insert(temp->val);
            if(temp->left){
                q1.push({temp->left,{x-1,y+1}});
            }
            
            if(temp->right){
                q1.push({temp->right,{x+1,y+1}});
            }
        }
        
        for(auto it:mp){
            vector<int> temp;
            for(auto it1:it.second){
                for(auto it2:it1.second)
                    temp.push_back(it2);
            }
            res.push_back(temp);
        }
        return res;
    }
};