class Solution {
public:
    bool findSol(vector<vector<int>>& adj,int start,vector<bool>& visited,vector<bool>& path){
        visited[start]=true;
        path[start]=true;
        for(auto &it:adj[start]){
            if(!visited[it]){
                if(findSol(adj,it,visited,path))
                    return true;
            }
            else if(path[it])
                return true;
        }
        path[start]=false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses,false),path(numCourses,false);
        for(auto &it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i])
                if(findSol(adj,i,visited,path))
                    return false;
        }
        return true;
    }
};