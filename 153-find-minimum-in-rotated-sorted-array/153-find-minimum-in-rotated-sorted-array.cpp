class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<hi and nums[lo]>nums[hi]){
            int mid=lo+(hi-lo)/2;
            if(nums[hi]<nums[mid])
                lo=mid+1;
            else
                hi=mid;
        }
        return nums[lo];
    }
};