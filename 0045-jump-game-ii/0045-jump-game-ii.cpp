class Solution {
public:
    int jump(vector<int>& nums) {
        int start=0,end=0,cnt=0;
        int n=nums.size();
        
        while(end<n-1){
            int maxEnd=end+1;
            for(int i=start;i<=end;i++){
                maxEnd=max(maxEnd,i+nums[i]);
            }
            cnt++;
            start=end;
            end=maxEnd;
        }
        return cnt;
    }
};