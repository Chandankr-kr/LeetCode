class Solution {
public:
    int findSol(int i,vector<int>& vals,vector<vector<int>> &adj,int k,vector<bool>& vis){
        priority_queue<int> pq1;
        int res=INT_MIN;
        vis[i]=true;
        for(auto &it:adj[i]){
            if(vals[it]>0)
                pq1.push(vals[it]);
            if(vis[it]==false){
                res=max(res,findSol(it,vals,adj,k,vis));
            }
        }
        int sum=vals[i];
        while(k and pq1.size()){
            sum+=pq1.top();
            pq1.pop();
            k--;
        }
        return max(res,sum);
    }
    
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size(),res=INT_MIN;
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<n;i++){
            res=max(res,findSol(i,vals,adj,k,vis));
        }
        return res;
    }
};