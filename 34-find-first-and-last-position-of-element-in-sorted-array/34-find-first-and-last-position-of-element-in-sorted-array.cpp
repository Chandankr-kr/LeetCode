class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0 or (n==1 and nums[0]!=target)  or nums[n-1]<target or *lower_bound(nums.begin(),nums.end(),target)!=target)
            return {-1,-1};
        vector<int> res;
        if(nums[0]==target){
            res.push_back(0);
        }
        else{
            auto it=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            if(nums[it]==target)
                res.push_back(it);
            else
                res.push_back(-1);
        }
        
        if(nums[n-1]==target){
            res.push_back(n-1);
        }
        else{
            auto it=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
            if(nums[it-1]==target)
                res.push_back(it-1);
            else
                res.push_back(-1);
        }
        return res;
    }
};