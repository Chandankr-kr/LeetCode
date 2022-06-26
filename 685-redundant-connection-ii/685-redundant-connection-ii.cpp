class Solution {
public:
    int findParent(vector<int>& parent,int i){
        if(parent[i]==i)
            return i;
        return parent[i]=findParent(parent,parent[i]);
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> v1,v2,parent(n+1,-1);
        vector<int> path(n+1,-1);
        
        for(auto &it:edges){
            if(path[it[1]]==-1){
                path[it[1]]=it[0];
            }
            else{
                v1={path[it[1]],it[1]};
                v2=it;
                break;
            }
        }
        
        for(int i=0;i<=n;i++)
            parent[i]=i;
        
        for(auto &it:edges){
            if(v2.size()>0 and v2==it)
                continue;
            
            int x=findParent(parent,it[0]);
            int y=findParent(parent,it[1]);
            if(x==y){
                if(v1.size()>0)
                    return v1;
                else
                    return it;
            }
            else{
                parent[x]=y;
            }
        }
        
        return v2;
    }
};