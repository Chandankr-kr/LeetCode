class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto u:nums)
        {
            if(pq.size()<k)
                pq.push(u);
            else
            {
                if(pq.top()<u)
                {
                    pq.pop();
                    pq.push(u);
                }
            }
        }
        return pq.top();
    }
};