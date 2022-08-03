class Solution {
public:
    int findSol(vector<int>& prices,int k,int ind,bool buy,vector<vector<vector<int>>> &dp){
        if(ind==prices.size())
            return 0;
        if(k==0)
            return 0;
        if(dp[k][ind][buy]!=-1)
            return dp[k][ind][buy];
        if(buy){
            int buyy=-prices[ind]+findSol(prices,k,ind+1,!buy,dp);
            int notbuy=findSol(prices,k,ind+1,buy,dp);
            return dp[k][ind][buy]=max(buyy,notbuy);
        }
        else{
            int sell=prices[ind]+findSol(prices,k-1,ind+1,!buy,dp);
            int notsell=findSol(prices,k,ind+1,buy,dp);
            return dp[k][ind][buy]=max(sell,notsell);
        }
    }
    
    
    int maxProfit(int k, vector<int>& prices){
        int n=prices.size();
        if(n<=1)
            return 0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return findSol(prices,k,0,true,dp);
    }
};