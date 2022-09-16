class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> q1;
        q1.push({sr,sc});
        
        while(q1.size()){
            auto it=q1.front();
            q1.pop();
            int x=it.first;
            int y=it.second;
            
            if(x-1>=0 and grid[x][y]==grid[x-1][y] and visited[x-1][y]==false){
                q1.push({x-1,y});
            }
            
            if(y-1>=0 and grid[x][y]==grid[x][y-1] and visited[x][y-1]==false){
                q1.push({x,y-1});
            }
            
            if(x+1<m and grid[x][y]==grid[x+1][y] and visited[x+1][y]==false){
                q1.push({x+1,y});
            }
            
            if(y+1<n and grid[x][y]==grid[x][y+1] and visited[x][y+1]==false){
                q1.push({x,y+1});
            }
            
            grid[x][y]=color;
            visited[x][y]=true;
        }
        return grid;
    }
};