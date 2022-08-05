class Solution {
public:
    vector<vector<int>> temp;
    int findSol(string &str,int start,int end){
        if(end<start)
            return 0;
        
        if(temp[start][end]!=-1)
            return temp[start][end];
        int res=0;
        if(start!=end && str[start]==str[end])
            res=2+findSol(str,start+1,end-1);
        else if(start==end && str[start]==str[end])
            res=1+findSol(str,start+1,end-1);
        else
            res=max({res,findSol(str,start+1,end),findSol(str,start,end-1)});
        return temp[start][end]=res;
    }
    int minInsertions(string s) {
        int n=s.size();
        temp.resize(n,vector<int>(n,-1));
        int res=findSol(s,0,n-1);
        return n-res;
    }
};