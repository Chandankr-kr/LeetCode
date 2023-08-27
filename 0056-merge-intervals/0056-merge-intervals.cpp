class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int temp=0;
        
        for(int i=1;i<n;i++){
            if(intervals[temp][1]>=intervals[i][0]){
                intervals[temp][1]=max(intervals[temp][1],intervals[i][1]);
            }
            else{
                intervals[++temp]=intervals[i];
            }
        }
        intervals.erase(intervals.begin()+temp+1,intervals.end());
        return intervals;
    }
};