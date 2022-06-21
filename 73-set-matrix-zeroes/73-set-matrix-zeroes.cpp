class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int col=1;
        
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0)
                col=0;
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>0;j--){
                if(!matrix[i][0] or !matrix[0][j])
                    matrix[i][j]=0;
            }
            if(!col)
                matrix[i][0]=0;
        }
        
    }
};