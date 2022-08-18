class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0],mini=nums[0],res=nums[0];
        for(int i=1;i<n;i++){
            int a=max(mini*nums[i],maxi*nums[i]);
            int b=min(mini*nums[i],maxi*nums[i]);
            maxi=max(nums[i],a);
            mini=min(nums[i],b);
            res=max(res,maxi);
            if(maxi==0)
                maxi=1;
            if(mini==0)
                mini=1;
        }
        return res;
    }
};