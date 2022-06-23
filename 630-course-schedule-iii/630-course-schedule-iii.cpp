class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int>& a,vector<int>& b){return a[1]<b[1];});
        priority_queue<int> pq1;
        int cost=0;
        
        for(auto &it:courses){
            if(it[0]+cost<=it[1]){
                cost+=it[0];
                pq1.push(it[0]);
            }
            else if(pq1.size() and pq1.top()>it[0]){
                cost-=pq1.top();
                pq1.pop();
                pq1.push(it[0]);
                cost+=it[0];
            }
        }
        return pq1.size();
    }
};