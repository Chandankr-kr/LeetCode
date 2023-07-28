class Solution {
public:
    int dp[21][21];
    int findSol(vector<int>& nums,int start,int end,int flag){
        if(start==end)
            return flag*nums[start];
        if(dp[start][end]!=-1)
            return dp[start][end];
        int res1=flag*nums[start]+findSol(nums,start+1,end,-flag);
        int res2=flag*nums[end]+findSol(nums,start,end-1,-flag);
        return dp[start][end]=flag*max(flag*res1,flag*res2);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int res=findSol(nums,0,n-1,1);
        return res>=0;
    }
};