class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size()-1;
        int n=matrix[0].size()-1;
        int l=0,r=n,u=0,d=m;
        
        while(l<=r and u<=d){
            for(int i=l;i<=r;i++){
                res.push_back(matrix[u][i]);
            }
            u++;
            if(u>d)
                break;
            
            for(int i=u;i<=d;i++){
                res.push_back(matrix[i][r]);
            }
            r--;
            if(l>r)
                break;
            
            for(int i=r;i>=l;i--){
                res.push_back(matrix[d][i]);
            }
            d--;
            if(u>d)
                break;
            
            for(int i=d;i>=u;i--){
                res.push_back(matrix[i][l]);
            }
            l++;
            if(l>r)
                break;
        }
        return res;
    }
};