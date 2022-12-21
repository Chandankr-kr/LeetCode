class Solution {
public:
    bool findSol(vector<vector<int>>& adj,int start,vector<bool>& visited,vector<bool>& color){
        visited[start]=true;
        for(auto it:adj[start]){
            if(visited[it]==false){
                color[it]=!color[start];
                if(findSol(adj,it,visited,color))
                    return true;
            }
            else if(color[start]==color[it])
                return true;
        }
        return false;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            adj[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        }
        
        vector<bool> visited(n,false);
        vector<bool> color(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                if(findSol(adj,i,visited,color))
                    return false;
            }
        }
        return true;
    }
};