class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if(*max_element(nums.begin(),nums.end())<0)
            return *max_element(nums.begin(),nums.end());
        
        int n=nums.size(),minSum=0,maxSum=0,maxRes=INT_MIN,minRes=INT_MAX,sum=0;
        for(auto it:nums){
            sum+=it;
        }
        
        for(int i=0;i<n;i++){
            minSum+=nums[i];
            minRes=min(minRes,minSum);
            if(minSum>0)
                minSum=0;
            
            maxSum+=nums[i];
            maxRes=max(maxRes,maxSum);
            if(maxSum<0)
                maxSum=0;
            
        }
        cout<<minSum;
        return max(maxRes,sum-minRes);
    }
};