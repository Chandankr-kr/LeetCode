class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int start=0,end=0,cnt=0;
        while(end<n-1){
            int maxEnd=start+1;
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