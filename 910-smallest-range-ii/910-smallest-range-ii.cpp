class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1)
            return 0;
        int res=nums[n-1]-nums[0];
        
        for(int i=0;i<n-1;i++){
            int a=nums[i];
            int b=nums[i+1];
            int minm=min(nums[0]+k,b-k);
            int maxm=max(nums[n-1]-k,a+k);
            res=min(res,maxm-minm);
        }
        return res;
    }
};