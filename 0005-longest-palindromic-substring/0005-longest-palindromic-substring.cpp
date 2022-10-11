class Solution {
public:
    string res;
    void findSol(string &str,int left,int right){
        if(left<0 or right>=str.size() or str[left]!=str[right])
            return;
        int size=right-left+1;
        if(res.size()<=size)
            res=str.substr(left,size);
        findSol(str,left-1,right+1);
    }
    
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1)
            return s;
        res=s[0];
        for(int i=1;i<n;i++){
            findSol(s,i-1,i);
            findSol(s,i-1,i+1);
        }
        return res;
    }
};