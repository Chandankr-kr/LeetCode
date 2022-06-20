class Solution {
public:
    vector<vector<string>> result;
    bool findPos(vector<string> queen,int col,int row,int n){
        for(int i=row-1;i>=0;i--){
            if(queen[i][col]=='Q')
                return false;
        }
        
        for(int i=row-1,j=col+1;i>=0 and j<n;i--,j++){
            if(queen[i][j]=='Q')
                return false;
        }
        
        for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--){
            if(queen[i][j]=='Q')
                return false;
        }
        return true;
    }
    
    void findSol(vector<string> queen,int row,int n){
        if(row==n){
            result.push_back(queen);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(findPos(queen,i,row,n)){
                queen[row][i]='Q';
                findSol(queen,row+1,n);
                queen[row][i]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string str="";
        for(int i=0;i<n;i++)
            str+=".";
        vector<string> queen(n,str);
        findSol(queen,0,n);
        return result;
    }
};