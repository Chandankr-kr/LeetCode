class Solution {
public:
    
    bool findSol(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<int>> &result)
    {
        if(k==s3.size())
            return true;
        if(result[i][j]!=-1)
            return result[i][j];
        bool res=false;
        if(i<s1.size() && s1[i]==s3[k])
            res=res || findSol(s1,s2,s3,i+1,j,k+1,result);
        if(j<s2.size() && s2[j]==s3[k])
            res=res || findSol(s1,s2,s3,i,j+1,k+1,result);
        return result[i][j]=res;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        vector<vector<int>> result(s1.size()+1,vector<int>(s2.size()+1,-1));
        return findSol(s1,s2,s3,0,0,0,result);
    }
};