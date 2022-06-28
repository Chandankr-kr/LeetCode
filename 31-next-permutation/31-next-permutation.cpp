class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int cnt=1,n=nums.size(),ind;
        for(int i=0;i<n-1;i++){
            if(nums[i]>=nums[i+1])
                cnt++;
        }
        if(cnt==n)
            return reverse(nums.begin(),nums.end());
        
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                ind=i-1;
                break;
            }
        }
        
        for(int i=n-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        
        sort(nums.begin()+ind+1,nums.end());
    }
};