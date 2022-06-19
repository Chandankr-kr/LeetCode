class Solution {
public:
    int longestSubsequence(string s, int k) {
        int res=0,cnt=0,pow=1,n=s.size();
        
        for(int i=n-1;i>=0 and res+pow<=k;i--){
            if(s[i]=='1'){
                cnt++;
                res+=pow;
            }
            pow<<=1;
        }
        return count(begin(s),end(s),'0')+cnt;
    }
};