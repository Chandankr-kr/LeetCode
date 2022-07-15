class Solution {
public:
    void findSol(vector<vector<int>>& grid,int x,int y,int m,int n){
        if(x<0 || y<0 || x>=m || y>=n)
            return;
        grid[x][y]=0;
        if(x-1>=0 && grid[x-1][y]){
            findSol(grid,x-1,y,m,n);
        }
        
        if(y-1>=0 && grid[x][y-1]){
            findSol(grid,x,y-1,m,n);
        }
        
        if(x+1<m && grid[x+1][y]){
            findSol(grid,x+1,y,m,n);
        }
        
        if(y+1<n && grid[x][y+1]){
            findSol(grid,x,y+1,m,n);
        }
        
    }
    
    void findRes(vector<vector<int>>& grid,int x,int y,int m,int n,int &cnt){
        if(x<0 || y<0 || x>=m || y>=n)
            return;
        cnt++;
        grid[x][y]=0;
        
        if(x-1>=0 && grid[x-1][y]){
            findRes(grid,x-1,y,m,n,cnt);
        }
        
        if(y-1>=0 && grid[x][y-1]){
            findRes(grid,x,y-1,m,n,cnt);
        }
        
        if(x+1<m && grid[x+1][y]){
            findRes(grid,x+1,y,m,n,cnt);
        }
        
        if(y+1<n && grid[x][y+1]){
            findRes(grid,x,y+1,m,n,cnt);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(grid[i][j]=='1'){
                        findSol(grid,i,j,m,n);
                    }
                }
            }
        }
        
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    int cnt=0;
                    findRes(grid,i,j,m,n,cnt);
                    res=max(res,cnt);
                }
            }
        }
        return res;
    }
};