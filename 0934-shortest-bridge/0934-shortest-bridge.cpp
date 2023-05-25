class Solution {
public:
    int paint(vector<vector<int>> &grid,int i,int j){
        if(min(i,j)<0 or max(i,j)==grid.size() or grid[i][j]!=1)
            return 0;
        grid[i][j]=2; 
        return 1+paint(grid,i-1,j)+paint(grid,i+1,j)+paint(grid,i,j-1)+paint(grid,i,j+1);
    }
    
    bool expand(vector<vector<int>>& grid,int i,int j,int cl){
        if(min(i,j)<0 or max(i,j)==grid.size())
            return false;
        grid[i][j]=grid[i][j]==0?cl+1:grid[i][j];
        return grid[i][j]==1;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        for(int i=0,found=0;found==0 and i<grid.size();i++){
            for(int j=0;found==0 and j<grid[0].size();j++){
                found=paint(grid,i,j);
            }
        }
        
        for(int cl=2;;++cl){
            for(int i=0;i<grid.size();++i){
                for(int j=0;j<grid[0].size();++j){
                    if(grid[i][j]==cl and (expand(grid,i-1,j,cl) or expand(grid,i+1,j,cl) or                                            expand(grid,i,j-1,cl) or expand(grid,i,j+1,cl)))
                        return cl-2;
                }
            }
        }
    }
};