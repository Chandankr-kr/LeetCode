class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res=0,n=nums.size();
        unordered_set<int> s1;
        for(auto &it:nums){
            s1.insert(it);
        }
        
        for(int i=0;i<n;i++){
            if(s1.find(nums[i]-1)==s1.end()){
                int cnt=0;
                int k=nums[i];
                while(s1.find(k)!=s1.end()){
                    cnt++;
                    k++;
                }
                res=max(res,cnt);
            }
        }
        return res;
    }
};