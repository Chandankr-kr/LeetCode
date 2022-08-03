class Solution {
public:
    int dp[201][201];
    bool findSol(string &s1,string &s2,string &s3,int i,int j,int k){
        if(s3.size()==k)
            return true;
        if(dp[i][j]!=-1)
            return dp[i][j];
        bool res=false;
        if(i<s1.size() and s1[i]==s3[k]){
            res=res or findSol(s1,s2,s3,i+1,j,k+1);
        }
        if(j<s2.size() and s3[k]==s2[j]){
            res=res or findSol(s1,s2,s3,i,j+1,k+1);
        }
        return dp[i][j]=res;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        memset(dp,-1,sizeof dp);
        return findSol(s1,s2,s3,0,0,0);
    }
};