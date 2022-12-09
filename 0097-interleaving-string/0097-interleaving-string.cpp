class Solution {
public:
    bool findSol(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<int>> &dp){
        if(k==s3.size())
            return true;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        bool res=false;
        if(i<s1.size() and s1[i]==s3[k]){
            res=res or findSol(s1,s2,s3,i+1,j,k+1,dp);
        }
        
        if(j<s2.size() and s2[j]==s3[k]){
            res=res or findSol(s1,s2,s3,i,j+1,k+1,dp);
        }
        return dp[i][j]=res;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();
        int n=s2.size();
        if(m+n!=s3.size())
            return false;
        vector<vector<int>> dp(201,vector<int> (201,-1));
        return findSol(s1,s2,s3,0,0,0,dp);
    }
};