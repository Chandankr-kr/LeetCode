class Solution {
public:
    int findSol(string &str1, string &str2,int m,int n,vector<vector<int>> &res){
        if(str1.size()==m or str2.size()==n)
            return 0;
        if(res[m][n]!=-1)
            return res[m][n];
        int result=0;
        if(str1[m]==str2[n]){
            result=1+findSol(str1,str2,m+1,n+1,res);
        }
        else{
            result=max(findSol(str1,str2,m+1,n,res),findSol(str1,str2,m,n+1,res));
        }
        return res[m][n]=result;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> res(m,vector<int>(n,-1));
        return findSol(text1,text2,0,0,res);
    }
};