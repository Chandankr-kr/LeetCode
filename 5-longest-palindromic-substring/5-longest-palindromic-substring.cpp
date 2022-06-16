class Solution {
public:
    string res="";
    void findSol(string &str,int left,int right){
        if(left<0 or right>=str.size() or str[left]!=str[right])
            return;
        if(str[left]==str[right]){
            int k=right-left+1;
            if(res.size()<k)
                res=str.substr(left,k);
        }
        findSol(str,left-1,right+1);
        return;
    }
    
    string longestPalindrome(string s) {
        int  n=s.size();
        res=s[0];
        for(int i=1;i<n;i++){
            findSol(s,i-1,i);
            findSol(s,i-1,i+1);
        }
        return res;
    }
};