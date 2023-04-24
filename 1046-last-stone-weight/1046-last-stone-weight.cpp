class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq1;
        for(auto &it:stones){
            pq1.push(it);
        }
        while(pq1.size()>1){
            int a=pq1.top();
            pq1.pop();
            int b=pq1.top();
            pq1.pop();
            if(a==b){
                if(!pq1.size())
                    return 0;
                continue;
            }
            else{
                pq1.push(abs(a-b));
            }
        }  
        return pq1.top();
    }
};