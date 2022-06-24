class Solution {
public:
    void findSol(vector<vector<int>>& adj,int start,vector<bool> &visited){
        visited[start]=true;
        for(auto &it:adj[start]){
            if(!visited[it])
                findSol(adj,it,visited);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),cnt=0;
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                findSol(adj,i,visited);
            }
        }
        return cnt;
    }
};