class Solution {
public:
    int findSol(vector<int> &nums,int start,int end,vector<int>& v1){
        if(start>end)
            return 0;
        if(v1[start]!=-1)
            return v1[start];
        return v1[start]=max(nums[start]+findSol(nums,start+2,end,v1),findSol(nums,start+1,end,v1));
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int n=nums.size();
        vector<int> v1(n,-1),v2(n,-1);
        int res1=findSol(nums,0,n-2,v1);
        int res2=findSol(nums,1,n-1,v2);
        return max(res1,res2);
    }
};