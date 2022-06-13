class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int res=0,n=nums.size(),cnt=0;
        for(int i=0;i<n-1;i++,cnt*=-1){
            if(nums[i]>nums[i+1])
                cnt=cnt>0?cnt+1:1;
            else if(nums[i]<nums[i+1])
                cnt=cnt<0?cnt-1:-1;
            else
                cnt=0; //   when adjacent elements are equal;
            res=max(res,abs(cnt));
        }
        return res+1;
    }
};