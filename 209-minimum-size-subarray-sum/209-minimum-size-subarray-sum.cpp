class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res=INT_MAX,n=nums.size(),sum=0,j=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                sum-=nums[j++];
                res=min(res,i-j+1);
            }
        }
        return res==INT_MAX?0:res+1;
    }
};