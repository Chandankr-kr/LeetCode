class Solution {
public:
    void findSol(string &str,int l,int r,string &res){
        if(l<0 or r>=str.size() or str[l]!=str[r])
            return;
        int len=r-l+1;
        if(len>=res.size())
            res=str.substr(l,len);
        findSol(str,l-1,r+1,res);
    }
    
    string longestPalindrome(string s) {
        string res="";
        res+=s[0];
        int n=s.size();
        if(n<=1)
            return s;
        
        for(int i=1;i<n;i++){
            findSol(s,i-1,i,res);
            findSol(s,i-1,i+1,res);
        }
        return res;
    }
};