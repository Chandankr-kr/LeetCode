class Solution {
public:
    int findParent(int x,vector<int>& parent){
        if(x==parent[x])
            return x;
        return parent[x]=findParent(parent[x],parent);
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parentAlice(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            parentAlice[i]=i;
        }
        
        for(auto &it:edges){
            it[1]--,it[2]--;
            if(it[0]==1 or it[0]==2)
                continue;
            int p1=findParent(it[1],parentAlice);
            int p2=findParent(it[2],parentAlice);
            if(p1!=p2){
                parentAlice[p1]=p2;
                cnt++;
            }
        }
        
        vector<int> parentBob(parentAlice);
        for(auto &it:edges){
            if(it[0]==1 or it[0]==3)
                continue;
            int p1=findParent(it[1],parentBob);
            int p2=findParent(it[2],parentBob);
            if(p1!=p2){
                parentBob[p1]=p2;
                cnt++;
            }
        }
        
        
        for(auto &it:edges){
            if(it[0]==2 or it[0]==3)
                continue;
            int p1=findParent(it[1],parentAlice);
            int p2=findParent(it[2],parentAlice);
            if(p1!=p2){
                parentAlice[p1]=p2;
                cnt++;
            }
        }
        
        for(int i=0;i<n;i++){
            findParent(i,parentAlice);
        }
        
        for(int i=0;i<n;i++){
            findParent(i,parentBob);
        }
        
        for(int i=1;i<n;i++){
            if(parentAlice[i]!=parentAlice[0])
                return -1;
        }
        
        for(int i=1;i<n;i++){
            if(parentBob[i]!=parentBob[0])
                return -1;
        }
        
        return edges.size()-cnt;
    }
};