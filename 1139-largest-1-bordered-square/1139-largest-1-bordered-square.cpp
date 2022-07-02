class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size(),res=0;
        vector<vector<int>> row(m,vector<int>(n,0));
        vector<vector<int>> col(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0 and grid[i][j]){
                    row[i][j]=1;
                }
                else if(grid[i][j]){
                    row[i][j]=row[i][j-1]+1;
                }
                
                if(i==0 and grid[i][j]){
                    col[i][j]=1;
                }
                else if(grid[i][j]){
                    col[i][j]=col[i-1][j]+1;
                }
            }
        }
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int temp=min(row[i][j],col[i][j]);
                while(temp>res){
                    if(row[i+1-temp][j]>=temp and col[i][j+1-temp]>=temp){
                        res=temp;
                    }
                    temp--;
                }
            }
        }
        return res*res;
    }
};