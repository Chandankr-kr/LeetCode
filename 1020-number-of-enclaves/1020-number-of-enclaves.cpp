class Solution {
public:
    void findSol(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i<0 or j<0 or i>=m or j>=n)
            return;
        grid[i][j]=0;
        if(i-1>=0 and grid[i-1][j]==1){
            findSol(grid,i-1,j,m,n);
        }
        
        if(j-1>=0 and grid[i][j-1]==1){
            findSol(grid,i,j-1,m,n);
        }
        
        if(i+1<m and grid[i+1][j]==1){
            findSol(grid,i+1,j,m,n);
        }
        
        if(j+1<n and grid[i][j+1]==1){
            findSol(grid,i,j+1,m,n);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 or i==m-1 or j==0 or j==n-1){
                    if(grid[i][j]==1){
                        findSol(grid,i,j,m,n);
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};