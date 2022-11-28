class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return;
        int cnt=0,key;
        
        for(int i=0;i<n-1;i++){
            if(nums[i]>=nums[i+1])
                cnt++;
        }
        if(cnt==n-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                key=i-1;
                break;
            }
        }
        
        for(int i=n-1;i>key;i--){
            if(nums[i]>nums[key]){
                swap(nums[i],nums[key]);
                break;
            }
        }
        
        sort(nums.begin()+key+1,nums.end());
    }
};