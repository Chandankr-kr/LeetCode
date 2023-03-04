class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res=0;
        int maxInd=-1,minInd=-1,latestInd=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxK or nums[i]<minK){
                maxInd=-1;
                minInd=-1;
                latestInd=i+1;
            }
            
            if(nums[i]==minK)
                minInd=i;
            if(nums[i]==maxK)
                maxInd=i;
            res+=max(0,min(maxInd,minInd)-latestInd+1);
        }
        return res;
    }
};