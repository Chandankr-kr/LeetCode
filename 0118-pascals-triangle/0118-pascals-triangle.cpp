class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        if(numRows==1)
            return res;
        res.push_back({1,1});
        
        for(int i=2;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<=res[i-1].size();j++){
                if(j==0)
                    temp.push_back(res[i-1][j]);
                else if(j==res[i-1].size())
                    temp.push_back(res[i-1][j-1]);
                else{
                    temp.push_back(res[i-1][j]+res[i-1][j-1]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};