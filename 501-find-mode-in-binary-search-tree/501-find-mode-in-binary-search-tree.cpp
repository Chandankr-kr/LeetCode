class Solution {
public:
    unordered_map<int,int> mp;
    void findSol(TreeNode* root){
        if(!root)
            return;
        mp[root->val]++;
        findSol(root->left);
        findSol(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        findSol(root);
//         for(auto &it:mp){
//             cout<<it.first<<" "<<it.second<<endl;
//         }
        
        vector<int> res,v1;
        priority_queue<pair<int,int>> pq1;
        bool flag=false;
        for(auto &it:mp){
            pq1.push({it.second,it.first});
        }
    
        while(pq1.size()){
            auto t=pq1.top();
            pq1.pop();
            int n=res.size();
            if(!flag){
                res.push_back(t.second);
                flag=true;
            }
            else{
                if(mp[res[n-1]]==t.first)
                    res.push_back(t.second);
                else
                    return res;
            }
        }
        return res;
    }
};