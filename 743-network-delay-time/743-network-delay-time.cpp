class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k){
        vector<int> wt(n+1,1e9+7);
        vector<vector<pair<int,int>>> adj(n+1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq1;
        for(auto &it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        wt[k]=0;
        wt[0]=0;
        pq1.push({0,k});
        
        while(pq1.size()){
            auto it=pq1.top();
            pq1.pop();
            int c=it.first;
            int v=it.second;
            for(auto &u:adj[v]){
                if(c+u.second<wt[u.first]){
                    wt[u.first]=c+u.second;
                    pq1.push({c+u.second,u.first});
                }
            }
        }
        int res=*max_element(wt.begin(),wt.end());
        return res==1e9+7?-1:res;
    }
};