class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int,int>> v1;
        for(int i=0;i<nums.size();i++)
        {
            v1.push_back({nums[i],i});
        }
            sort(v1.begin(),v1.end());
            
        // for(int i=0;i<nums.size();i++)
        // {
        //     cout<<v1[i].first<<" "<<v1[i].second<<endl;
        // }
            for(int i=0;i<nums.size()-1;i++)
            {
                if(v1[i].first==v1[i+1].first)
                {
                    if((abs(v1[i].second-v1[i+1].second))<=k)
                        return true;
                }
            }
        return false;
    }
};