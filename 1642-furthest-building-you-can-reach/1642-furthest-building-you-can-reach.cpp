class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq1;
        int n=heights.size();
        for(int i=0;i<n-1;i++){
            int d=heights[i]-heights[i+1];
            if(d<0)
                pq1.push(d);
            if(pq1.size()>ladders){
                bricks+=pq1.top();
                pq1.pop();
            }
            if(bricks<0)
                return i;
        }
        return n-1;
    }
};