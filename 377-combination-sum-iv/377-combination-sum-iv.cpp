class Solution {
public:
    vector<int> dp;
    int findSol(vector<int>& nums,int target){
        if(target==0)
            return 1;
        if(target<0)
            return 0;
        if(dp[target]!=-1)
            return dp[target];
        int res=0;
        
        for(int i=0;i<nums.size();i++){
            res+=findSol(nums,target-nums[i]);
        }
        return dp[target]=res;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(1002,-1);
        return findSol(nums,target);
    }
};