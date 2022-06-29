class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res=INT_MAX,n=nums.size(),j=0,sum=0,i=0;
        while(i<n){
            sum+=nums[i++];
            while(sum>=target){
                
                res=min(res,i-j);
                sum-=nums[j++];
            }
        }
        return res==INT_MAX?0:res;
    }
};