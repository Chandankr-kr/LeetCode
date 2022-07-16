class Solution {
public:
    int mod;
    int findSol(int x,int y,int m,int n,int maxMove,vector<vector<vector<int>>> &dp){
        if(x<0 or y<0 or x>=m or y>=n)
            return 1;
        if(maxMove==0)
            return 0;
        if(dp[x][y][maxMove]!=-1)
            return dp[x][y][maxMove];
        
        long int res=0;
        res+=findSol(x-1,y,m,n,maxMove-1,dp)%mod;
        res+=findSol(x+1,y,m,n,maxMove-1,dp)%mod;
        res+=findSol(x,y+1,m,n,maxMove-1,dp)%mod;
        res+=findSol(x,y-1,m,n,maxMove-1,dp)%mod;
        return dp[x][y][maxMove]=res%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        mod=1e9+7;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return findSol(startRow,startColumn,m,n,maxMove,dp);
    }
};