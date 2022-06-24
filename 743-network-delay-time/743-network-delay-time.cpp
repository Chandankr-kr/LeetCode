class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> wt(n+1,1e9+7);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq1;
        wt[k]=0;
        wt[0]=-1;
        pq1.push({0,k});
        for(auto &it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        while(pq1.size()){
            auto it=pq1.top();
            pq1.pop();
            int cost=it.first;
            int x=it.second;
            for(auto &it:adj[x]){
                if(wt[it.first]>it.second+wt[x]){
                    wt[it.first]=it.second+wt[x];
                    pq1.push({wt[it.first],it.first});
                }
            }
        }
        // for(int i=0;i<wt.size();i++)
        //     cout<<wt[i]<<" ";
        
        int res=*max_element(wt.begin(),wt.end());
        return res==1e9+7?-1:res;
    }
};