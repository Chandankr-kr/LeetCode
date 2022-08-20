class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> mp,freq;
        for(auto &it:nums){
            freq[it]++;
        }
        
        for(auto &it:nums){
            if(freq[it]==0)
                continue;
            else if(mp[it-1]>0){
                mp[it-1]--;
                mp[it]++;
                freq[it]--;
            }
            else if(freq[it+1]>0 and freq[it+2]>0){
                freq[it+1]--;
                freq[it+2]--;
                freq[it]--;
                mp[it+2]++;
            }
            else
                return false;
        }
        return true;
    }
};