class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int res=INT_MAX,min_no=INT_MAX;
        priority_queue<int> pq1;
        
        for(auto r:nums){
            if(r%2){
                pq1.push(r*2);
                min_no=min(min_no,r*2);
            }
            else{
                pq1.push(r);
                min_no=min(min_no,r);
            }
        }
        
        while(pq1.top()%2==0){
            res=min(res,pq1.top()-min_no);
            min_no=min(min_no,pq1.top()/2);
            pq1.push(pq1.top()/2);
            pq1.pop();
        }
        return min(res,pq1.top()-min_no);
    }
};