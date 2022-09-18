class Solution {
public:
    bool findSol(vector<vector<int>>& adj,int start,vector<bool>& visited,vector<bool>& mark){
        visited[start]=true;
        mark[start]=true;
        
        for(auto &it:adj[start]){
            if(visited[it]==false){
                if(findSol(adj,it,visited,mark))
                    return true;
            }
            else if(mark[it]==true)
                return true;
        }
        mark[start]=false;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false),mark(n,false);
        for(auto &it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                if(findSol(adj,i,visited,mark))
                    return false;
            }
        }
        return true;
    }
};