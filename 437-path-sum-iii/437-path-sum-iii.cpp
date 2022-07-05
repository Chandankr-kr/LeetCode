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
    unordered_map<int,int> mp;
    int cnt=0;
    
    void findSol(TreeNode* root,int target,long long int sum){
        if(root==NULL)
            return;
        sum+=root->val;
        if(target==sum)
            cnt++;
        if(mp.find(sum-target)!=mp.end())
            cnt+=mp[sum-target];
        mp[sum]++;
        findSol(root->left,target,sum);
        findSol(root->right,target,sum);
        mp[sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        findSol(root,targetSum,0);
        return cnt;
    }
};