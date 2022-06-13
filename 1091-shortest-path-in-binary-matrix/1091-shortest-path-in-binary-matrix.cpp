class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0])
            return -1;
        int res=INT_MAX;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,pair<int,int>>> pq1;
        pq1.push({1,{0,0}});
        visited[0][0]=true;
        while(pq1.size()){
            auto it=pq1.front();
            pq1.pop();
            int x=it.second.first;
            int y=it.second.second;
            int cost=it.first;
            if(x==m-1 and y==n-1)
                res=min(res,cost);
            
            if(x-1>=0 and !grid[x-1][y] and !visited[x-1][y]){
                pq1.push({cost+1,{x-1,y}});
                visited[x-1][y]=true;
            }
            
            if(y-1>=0 and !grid[x][y-1] and !visited[x][y-1]){
                pq1.push({cost+1,{x,y-1}});
                visited[x][y-1]=true;
            }
            
            if(x+1<m and !grid[x+1][y] and !visited[x+1][y]){
                pq1.push({cost+1,{x+1,y}});
                visited[x+1][y]=true;
            }
            
            if(y+1<n and !grid[x][y+1] and !visited[x][y+1]){
                pq1.push({cost+1,{x,y+1}});
                visited[x][y+1]=true;
            }
            
            
            if(y+1<n and x+1<m and !grid[x+1][y+1] and !visited[x+1][y+1]){
                pq1.push({cost+1,{x+1,y+1}});
                visited[x+1][y+1]=true;
            }
            
            if(y+1<n and x-1>=0 and !grid[x-1][y+1] and !visited[x-1][y+1]){
                pq1.push({cost+1,{x-1,y+1}});
                visited[x-1][y+1]=true;
            }
            
            if(y-1>=0 and x-1>=0 and !grid[x-1][y-1] and !visited[x-1][y-1]){
                pq1.push({cost+1,{x-1,y-1}});
                visited[x-1][y-1]=true;
            }
            
            if(y-1>=0 and x+1<m and !grid[x+1][y-1] and !visited[x+1][y-1]){
                pq1.push({cost+1,{x+1,y-1}});
                visited[x+1][y-1]=true;
            }
        }
        return res==INT_MAX?-1:res;
    }
};