class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,set<int>> adj;
        for(int i=0;i<trust.size();i++){
            adj[trust[i][0]-1].insert(trust[i][1]-1);
        }
        int temp=-1;
        for(int i=0;i<n;i++){
            if(adj[i].size()==0)
                temp=i;
        }
        if(temp==-1)
            return -1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(adj[i].find(temp)!=adj[i].end())
                cnt++;
        }
        if(cnt==n-1)
            return temp+1;
        else
            return -1;
    }
};