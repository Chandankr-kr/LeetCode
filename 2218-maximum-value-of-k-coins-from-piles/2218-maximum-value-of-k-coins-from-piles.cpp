class Solution {
public:
    int dp[1001][2001];
    int findSol(vector<vector<int>>& piles,int ind,int k){
        if(k==0 or ind==piles.size())
            return 0;
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        int res1=0,res2=0;
        res1=findSol(piles,ind+1,k);
        for(int i=0;i<piles[ind].size();i++){
            res2+=piles[ind][i];
            if(k-(i+1)>=0)
                res1=max(res1,res2+findSol(piles,ind+1,k-(i+1)));
        }
        return dp[ind][k]=res1;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof dp);
        return findSol(piles,0,k);
    }
};