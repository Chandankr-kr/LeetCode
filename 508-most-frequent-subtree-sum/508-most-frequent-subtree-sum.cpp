class Solution {
public:
    vector<int> res;
    int findSol(TreeNode* root){
        if(root==NULL)
            return 0;
        int left=findSol(root->left);
        int right=findSol(root->right);
        root->val+=left+right;
        res.push_back(root->val);
        return root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        findSol(root);
        vector<int> result;
        unordered_map<int,int> mp;
        int cnt=0;
        for(auto &it:res){
            mp[it]++;
            if(mp[it]>cnt)
                cnt=mp[it];
        }
        
        for(auto &it:res){
            if(mp[it]==cnt){
                result.push_back(it);
                mp.erase(it);
            }
        }
        return result;
    }
};