class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0,hi=n-1;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(target==nums[mid])
                return mid;
            else if(target>nums[mid])
                lo=mid+1;
            else
                hi=mid-1;
        }
        return -1;
    }
};