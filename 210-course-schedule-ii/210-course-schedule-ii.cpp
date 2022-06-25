class Solution {
public:
    vector<int> res;
    bool findSol(vector<vector<int>> &adj,int start,vector<bool>& visited,vector<bool>& path){
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
        res.push_back(start);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses,false),path(numCourses,false);
        for(auto &it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        
        for(int i=0;i<path.size();i++){
            if(!visited[i])
                if(findSol(adj,i,visited,path))
                    return {};
        }
        return res;
    }
};