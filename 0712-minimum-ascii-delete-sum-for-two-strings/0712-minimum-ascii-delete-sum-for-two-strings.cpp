class Solution {
public:
    int dp[1001][1001];
    int findSol(string &s1,string &s2,int ind1,int ind2){
        if(ind1==s1.size() or ind2==s2.size()){
            int res=0;
            if(ind1==s1.size()){
                while(ind2!=s2.size()){
                    res+=(int)s2[ind2++];
                }
            }
            else{
                while(ind1!=s1.size()){
                    res+=(int)s1[ind1++];
                }
            }
            return res;
        }
        
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        int res=0;
        if(s1[ind1]==s2[ind2]){
            res+=findSol(s1,s2,ind1+1,ind2+1);
        }
        else{
            int res1=(int)s1[ind1]+findSol(s1,s2,ind1+1,ind2);
            int res2=(int)s2[ind2]+findSol(s1,s2,ind1,ind2+1);
            res+=min({res1,res2});
        }
        return dp[ind1][ind2]=res;
    }
    
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return findSol(s1,s2,0,0);
    }
};