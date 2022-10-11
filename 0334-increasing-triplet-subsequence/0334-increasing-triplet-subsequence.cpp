class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            if(i==0 or nums[i]>res[res.size()-1])
                res.push_back(nums[i]);
            else{
                if(lower_bound(res.begin(),res.end(),nums[i])!=res.end()){
                    int t=lower_bound(res.begin(),res.end(),nums[i])-res.begin();
                    res[t]=nums[i];
                }
            }
        }
        if(res.size()>=3)
            return true;
        else
            return false;
    }
};