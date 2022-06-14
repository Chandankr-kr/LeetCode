class Solution {
public:
    int findSol(vector<int>& nums, int k){
        int res=0,cnt=0,start=0,n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]%2)
                k--;
            if(k<0){
                while(nums[start++]%2==0);
                    k++;
            }
            res+=i-start+1;    
        }
        return res;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return findSol(nums,k)-findSol(nums,k-1);
    }
};