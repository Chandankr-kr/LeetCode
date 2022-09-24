class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> weight(n+1,1e9+7);
        vector<vector<pair<int,int>>> adj(n+1);
        priority_queue<pair<int,int>> pq1;
        
        for(auto &it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        weight[0]=0;
        weight[k]=0;
        pq1.push({0,k});
        
        while(pq1.size()){
            int cost=pq1.top().first;
            int vertex=pq1.top().second;
            pq1.pop();
            for(auto &v:adj[vertex]){
                if(cost+v.second<weight[v.first]){
                    weight[v.first]=cost+v.second;
                    pq1.push({weight[v.first],v.first});
                }
            }
        }
        int res=*max_element(weight.begin(),weight.end());
        return res==1e9+7?-1:res;
    }
};