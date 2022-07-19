class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> v1={1};
        vector<int> v2={1,1};
        res.push_back(v1);
        if(numRows==1)
            return res;
        
        res.push_back(v2);
        if(numRows==2)
            return res;
        
        for(int i=3;i<=numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<i-1;j++){
                temp.push_back(res[i-2][j-1]+res[i-2][j]);
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};