class Solution {
public:
    vector<vector<int>> dp;
    int findSol(vector<int> &nums,int n,int amount)
    {
        if(amount==0)
            return 0;
        if(n==0 || amount<0)
            return INT_MAX-1;
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        if(nums[n-1]<=amount)
            return dp[n][amount]= min(findSol(nums,n-1,amount),1+findSol(nums,n,amount-nums[n-1]));
        else
            return dp[n][amount]= findSol(nums,n-1,amount);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.resize(n+1,vector<int>(amount+1,-1));
        long res=findSol(coins,n,amount);
        return res==INT_MAX-1?-1:res;
    }
};