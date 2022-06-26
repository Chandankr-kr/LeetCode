class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size()==0)
            return {0};
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0),res;
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        
        queue<int> q1;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==1)
                q1.push(i);
        }
        
        while(q1.size()){
            int n=q1.size();
            res.erase(res.begin(),res.end());
            for(int i=0;i<n;i++){
                int front=q1.front();
                q1.pop();
                res.push_back(front);
                for(auto &it:adj[front]){
                    indegree[it]--;
                    if(indegree[it]==1)
                        q1.push(it);
                }
            }
        }
        return res;
    }
};