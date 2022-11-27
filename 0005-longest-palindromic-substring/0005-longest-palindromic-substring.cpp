class Solution {
public:
    void findSol(string &str,string &res,int left,int right){
        if(left<0 or right>=str.size() or str[left]!=str[right])
            return;
        int k=right-left+1;
        if(res.size()<=k)
            res=str.substr(left,k);
        findSol(str,res,left-1,right+1);
    }
    
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1)
            return s;
        string res="";
        res+=s[0];
        for(int i=1;i<n;i++){
            findSol(s,res,i-1,i);
            findSol(s,res,i-1,i+1);
        }
        return res;
    }
};