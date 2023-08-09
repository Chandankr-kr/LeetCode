class Solution {
public:
    bool findSol(vector<vector<int>> &adj,int start,vector<bool> &visited,vector<bool> &mark){
        visited[start]=true;
        mark[start]=true;
        
        for(auto it:adj[start]){
            if(visited[it]==false){
                if(findSol(adj,it,visited,mark))
                    return true;
            }
            else if(mark[it])
                return true;
        }
        mark[start]=false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses,false);
        vector<bool> mark(numCourses,false);
        for(auto &it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(findSol(adj,i,visited,mark))
                return false;
        }
        return true;
    }
};