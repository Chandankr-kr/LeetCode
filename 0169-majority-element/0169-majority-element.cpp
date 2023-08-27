class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1;
        int res=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==res)
                cnt++;
            else
                cnt--;
            
            if(cnt==0){
                res=nums[i];
                cnt++;
            }
        }
        return res;
    }
};


