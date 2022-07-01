class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>> pq1;
        for(auto &it:boxTypes){
            pq1.push({it[1],it[0]});
        }
        
        int res=0;
        while(pq1.size()){
            auto it=pq1.top();
            pq1.pop();
            if(it.second>=truckSize){
                res+=truckSize*it.first;
                break;
            }
            else if(it.second<truckSize){
                res+=it.first*it.second;
                truckSize-=it.second;
            }
        }
        return res;
    }
};