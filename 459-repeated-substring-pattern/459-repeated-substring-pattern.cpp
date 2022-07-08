class Solution {
public:
    void findSol(string str,vector<int> &lps){
        int n=str.size(),i=1,j=0;
        while(i<n){
            if(str[i]==str[j]){
                lps[i]=j+1;
                i++,j++;
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
    }
    
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        vector<int> lps(n,0);
        findSol(s,lps);
        int k=lps[n-1];
        return k and (n%(n-k)==0);
    }
};