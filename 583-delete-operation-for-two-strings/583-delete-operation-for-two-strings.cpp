class Solution {
public:
    int dp[501][501];
    Solution(){
        memset(dp,-1,sizeof dp);
    }
    int findSol(string str1,string str2,int i,int j){
        if(i>=str1.size())
            return str2.size()-j;
        if( j>=str2.size())
            return str1.size()-i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(str1[i]==str2[j])
            return dp[i][j]= findSol(str1,str2,i+1,j+1);
        else
            return dp[i][j]= min({1+findSol(str1,str2,i+1,j),1+findSol(str1,str2,i,j+1),2+findSol(str1,str2,i+1,j+1)});
    }
    
    int minDistance(string word1, string word2) {
        return findSol(word1,word2,0,0);
    }
};