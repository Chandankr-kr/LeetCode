class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq1;
        vector<int> res;
        int n=nums.size();
        for(int i=0;i<k;i++){
            pq1.push({nums[i],i});
        }
        res.push_back(pq1.top().first);
        int j=0;
        
        for(int i=k;i<n;i++){
            pq1.push({nums[i],i});
            while(pq1.top().second<=j){
                pq1.pop();
            }
            res.push_back(pq1.top().first);
            j++;
        }
        return res;
    }
};