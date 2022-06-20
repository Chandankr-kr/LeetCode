class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mat(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 or j==0)
                    mat[i][j]=1;
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                mat[i][j]=mat[i-1][j]+mat[i][j-1];
            }
        }
        return mat[m-1][n-1];
    }
};