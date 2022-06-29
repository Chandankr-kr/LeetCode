class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res=INT_MAX,n=nums.size(),j=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                
                res=min(res,i-j+1);
                sum-=nums[j++];
            }
        }
        return res==INT_MAX?0:res;
    }
};