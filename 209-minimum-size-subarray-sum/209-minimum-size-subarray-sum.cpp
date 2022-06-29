class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res=INT_MAX;
        int i=0;
        int j=0;
        int sum=0;
        int n=nums.size();
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