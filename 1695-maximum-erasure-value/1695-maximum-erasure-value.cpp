class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res=0,start=0,sum=0,n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mp[nums[i]]++;
            while(mp[nums[i]]>1){
                sum-=nums[start];
                mp[nums[start]]--;
                start++;
            }
            res=max(res,sum);
        }
        return res;
    }
};