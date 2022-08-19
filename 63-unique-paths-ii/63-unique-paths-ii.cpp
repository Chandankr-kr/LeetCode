class Solution {
public:
    int dp[101][101];
    int findSol(vector<vector<int>>& grid,int x,int y,int m,int n){
        if(x==m-1 and y==n-1)
            return 1;
        if(grid[x][y]==1)
            return 0;
        if(dp[x][y]!=-1)
            return dp[x][y];
        int res=0;
        
        if(x+1<m)
            res+=findSol(grid,x+1,y,m,n);
        if(y+1<n)
            res+=findSol(grid,x,y+1,m,n);
        return dp[x][y]=res;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof dp);
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1])
            return 0;
        return findSol(obstacleGrid,0,0,m,n);
    }
};