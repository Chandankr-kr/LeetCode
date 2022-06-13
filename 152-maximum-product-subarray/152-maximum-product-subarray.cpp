class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),res=nums[0],maxi=nums[0],mini=nums[0];
        
        for(int i=1;i<n;i++){
            int a=max(nums[i],max(maxi*nums[i],mini*nums[i]));
            int b=min(nums[i],min(maxi*nums[i],mini*nums[i]));
            maxi=a;
            mini=b;
            res=max(res,maxi);
            if(maxi==0)
                maxi=1;
            if(mini==0)
                mini=1;
            
        }
        return res;
    }
};