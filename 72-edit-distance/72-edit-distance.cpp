class Solution {
public:
    int dp[502][502];
    int findSol(string& str1,int ind1,string &str2,int ind2){
        if(ind1==str1.size())
            return str2.size()-ind2;
        if(ind2==str2.size())
            return str1.size()-ind1;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        int res=0;
        if(str1[ind1]==str2[ind2])
            res = findSol(str1,ind1+1,str2,ind2+1);
        else{
            int insert=findSol(str1,ind1+1,str2,ind2);
            int remove=findSol(str1,ind1,str2,ind2+1);
            int replace=findSol(str1,ind1+1,str2,ind2+1);
            res = 1+min({insert,remove,replace});
        }
        return dp[ind1][ind2]=res;
    }
    
    int minDistance(string str1, string str2) {
        if(str1.size()==0)
            return str2.size();
        if(str2.size()==0)
            return str1.size();
        memset(dp,-1,sizeof dp);
        return findSol(str1,0,str2,0);
    }
};