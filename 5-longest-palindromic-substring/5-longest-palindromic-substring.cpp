class Solution {
public:
    int res=1;
    string str1="";
    void findSol(string &str,int left,int right){
        if(left<0 || right>=str.size())
            return;
        if(str[left]!=str[right])
            return;
        if(right-left+1>=res){
            res=right-left+1;
            str1=str.substr(left,res);
        }
        findSol(str,left-1,right+1);
        return;
    }
    
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1)
            return s;
        str1=s[0];
        for(int i=1;i<n;i++){
            findSol(s,i-1,i+1);
            findSol(s,i-1,i);
        }
        return str1;
    }
};