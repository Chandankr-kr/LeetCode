class Solution {
public:
    int findSol(vector<int> &coins,int ind,int amount,vector<vector<int>>& dp){
        if(amount==0){
            return 0;
        }
        
        if(amount<0 or ind==coins.size())
            return INT_MAX-1;
        
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        
        int res=0;
        if(amount>=coins[ind]){
            res=min(1+findSol(coins,ind,amount-coins[ind],dp),findSol(coins,ind+1,amount,dp));
        }
        else{
            res=findSol(coins,ind+1,amount,dp);
        }
        
        return dp[ind][amount]=res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int res=findSol(coins,0,amount,dp);
        return res==INT_MAX-1?-1:res;
    }
};