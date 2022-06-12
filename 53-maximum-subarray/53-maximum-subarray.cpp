class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(),res=INT_MIN;
        int sum=0;
        for(auto &it:nums){
            sum+=it;
            res=max(res,sum);
            if(sum<0)
                sum=0;
        }
        return res;
    }
};