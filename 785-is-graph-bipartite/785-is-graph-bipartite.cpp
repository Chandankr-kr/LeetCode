class Solution {
public:
    bool findSol(vector<vector<int>>& graph,int start,vector<bool>& color,vector<bool>& visited){
    
        queue<int> q1;
        q1.push(start);
        while(q1.size()){
            int n=q1.size();
            for(int i=0;i<n;i++){
                int front=q1.front();
                q1.pop();
                visited[front]=true;
                for(auto &it:graph[front]){
                    if(visited[it]==false){
                        visited[it]=true;
                        color[it]=!color[front];
                        q1.push(it);
                    }
                    else if(color[it]==color[front])
                        return true;
                }
            }
        }
        return false;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> color(n,false);
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(findSol(graph,i,color,visited))
                    return false;
            }
        }
        return true;
    }
};