class Solution {
public:
    int dp[501][501];
    int findSol(string str1,int ind1,string str2,int ind2){
        if(ind1==str1.size())
            return str2.size()-ind2;
        if(ind2==str2.size())
            return str1.size()-ind1;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        int res=0;
        if(str1[ind1]==str2[ind2]){
            res=findSol(str1,ind1+1,str2,ind2+1);
        }
        else{
            int r1=findSol(str1,ind1+1,str2,ind2);
            int r2=findSol(str1,ind1,str2,ind2+1);
            int r3=findSol(str1,ind1+1,str2,ind2+1);
            res = 1+min({r1,r2,r3});
        }
        return dp[ind1][ind2]=res;
    }
    
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        if(m==0)
            return n;
        if(n==0)
            return m;
        memset(dp,-1,sizeof dp);
        return findSol(word1,0,word2,0);
    }
};