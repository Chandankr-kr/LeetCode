class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int j=0;
        for(int i=1;i<n;i++){
            if(intervals[j][1]>=intervals[i][0]){
                intervals[j][1]=max(intervals[i][1],intervals[j][1]);
            }
            else{
                intervals[++j]=intervals[i];
            }
        }
        intervals.erase(intervals.begin()+j+1,intervals.end());
        return intervals;
    }
};