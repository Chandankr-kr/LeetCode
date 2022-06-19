class Solution {
public:
    
    int findSol(vector<int>& nums,int n,int i,vector<vector<int>> &dp){
        if(n<0 or i>=nums.size())
            return 10000000;
        if(n==0)
            return 0;
        if(dp[n][i]!=-1)
            return dp[n][i];
        return dp[n][i]=min(1+findSol(nums,n-nums[i],i,dp),findSol(nums,n,i+1,dp));
    }
    int minimumNumbers(int num, int t) {
        if( t== 0 && num == 0){
            return 0;
        }
        if(t == 0){
            return num%10 == 0? 1:-1;
        }
        if(num == 0){
            return 0;
        }
        
        vector<int> v1;
        int k=t;
        while(num>=k){
            v1.push_back(k);
            k=k+10;
        }
        reverse(v1.begin(),v1.end());
        vector<vector<int>> dp(num+1,vector<int>(v1.size()+1,-1));
        int p=findSol(v1,num,0,dp);
        return p>=10000000?-1:p;
    }
};