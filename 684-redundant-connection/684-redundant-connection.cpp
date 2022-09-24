class Solution {
public:
    int findParent(vector<int>& parent,int x){
        if(x==parent[x])
            return x;
        return parent[x]=findParent(parent,parent[x]);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1,-1),res(2,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        
        for(auto &it:edges){
            int x=findParent(parent,it[0]);
            int y=findParent(parent,it[1]);
            if(x==y){
                res[0]=it[0];
                res[1]=it[1];
            }
            else{
                parent[x]=y;
            }
        }
        return res;
    }
};