class Solution {
public:
    bool findSol(vector<int>& nums,vector<long long int>& preSum,int k,int target){
        int n=nums.size();
        
        for(int i=k-1;i<n;i++){
            long long int temp=(long long int)k*nums[i];
            if(i-k>=0){
                if(temp-(preSum[i]-preSum[i-k])<=target)
                    return true;
            }
            else{
                if(temp-(preSum[i])<=target)
                    return true;
            }
        }
        return false;
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size(),lo=1,hi=n,res=0;
        vector<long long int> preSum(n,0);
        sort(nums.begin(),nums.end());
        preSum[0]=nums[0];
        for(int i=1;i<n;i++){
            preSum[i]=preSum[i-1]+nums[i];
        }
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(findSol(nums,preSum,mid,k)){
                res=max(res,mid);
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return res;
    }
};