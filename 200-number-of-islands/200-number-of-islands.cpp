class Solution {
public:
    void findSol(vector<vector<char>>& grid,int x,int y,int m,int n){
        if(x<0 or y<0 or x>=m or y>=n)
            return;
        grid[x][y]='0';
        
        if(x-1>=0 and grid[x-1][y]=='1')
            findSol(grid,x-1,y,m,n);
        
        if(y-1>=0 and grid[x][y-1]=='1')
            findSol(grid,x,y-1,m,n);
        
        if(x+1<m and grid[x+1][y]=='1')
            findSol(grid,x+1,y,m,n);
        
        if(y+1<n and grid[x][y+1]=='1')
            findSol(grid,x,y+1,m,n);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    findSol(grid,i,j,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};