class Solution {
public:
    int findSol(string str1,string str2,int i,int j,vector<vector<int>> &dp){
        if(str1.size()==i)
            return str2.size()-j;
        if(str2.size()==j)
            return str1.size()-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int res=0;
        
        if(str1[i]==str2[j]){
            res=findSol(str1,str2,i+1,j+1,dp);
        }
        else{
            int r1=findSol(str1,str2,i,j+1,dp);
            int r2=findSol(str1,str2,i+1,j,dp);
            int r3=findSol(str1,str2,i+1,j+1,dp);
            res=1+min({r1,r2,r3});
        }
        return dp[i][j]=res;
    }
    
    int minDistance(string word1, string word2) {
        if(word1.size()==0)
            return word2.size();
        if(word2.size()==0)
            return word1.size();
        vector<vector<int>> dp(501,vector<int>(501,-1));
        return findSol(word1,word2,0,0,dp);
    }
};