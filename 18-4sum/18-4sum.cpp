class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<4)
            return {};
        sort(nums.begin(),nums.end());
        set<vector<int>> s1;
        vector<vector<int>> res;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int k=j+1,l=n-1;
                long long int sum=(long long int)target-(long long int)(nums[i]+nums[j]);
                while(k<l){
                    if(sum>nums[k]+nums[l])
                        k++;
                    else if(sum<nums[k]+nums[l])
                        l--;
                    else{
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        if(s1.find(temp)==s1.end())
                            res.push_back(temp);
                        s1.insert(temp);
                        k++,l--;
                    }
                }
            }
        }
        return res;
    }
};