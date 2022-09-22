class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        queue<pair<int,int>> q1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q1.push({i,j});
                }
            }
        }
        
        while(q1.size()){
            int k=q1.size();
            for(int i=0;i<k;i++){
                int x=q1.front().first;
                int y=q1.front().second;
                
                q1.pop();
                if(x-1>=0 and grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    q1.push({x-1,y});
                }
                
                if(y-1>=0 and grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    q1.push({x,y-1});
                }
                
                if(x+1<m and grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    q1.push({x+1,y});
                }
                
                if(y+1<n and grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    q1.push({x,y+1});
                }
            }
            cnt++;
        }
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return cnt-1==-1?0:cnt-1;
    }
};