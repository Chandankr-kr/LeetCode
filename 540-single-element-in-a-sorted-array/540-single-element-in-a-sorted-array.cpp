class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if((mid%2==0 and nums[mid]==nums[mid+1]) or (mid%2==1 and nums[mid]==nums[mid-1]))
                lo=mid+1;
            else
                hi=mid;
        }
        return nums[lo];
    }
};