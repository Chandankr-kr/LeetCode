class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                    res[i]=max(res[i],res[j]+1);
            }
        }
        return *max_element(res.begin(),res.end());
    }
};