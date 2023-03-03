class Solution {
public:
    vector<int> findLps(string needle){
        int n=needle.length();
        vector<int> lps(n);
        int i=1,j=0;
        while(i<n){
            if(needle[i]==needle[j]){
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
        return lps;
    }
    
    int strStr(string haystack, string needle) {
        vector<int> lps=findLps(needle);
        int m=haystack.size();
        int n=needle.size();
        int i=0,j=0;
        while(i<m and j<n){
            if(haystack[i]==needle[j]){
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
            
            if(j==n){
                return i-j;
            }
        }
        return -1;
    }
};