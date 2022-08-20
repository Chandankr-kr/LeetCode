class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt=0;
        int n=s.size(),zero=0,one=0;
        for(int i=0;i<n;i++){
            if(i==0){
                if(s[i]=='0')
                    zero++;
                else
                    one++;
            }
            else{
                if(s[i]=='0' and s[i-1]=='0'){
                    zero++;
                    if(one>=zero)
                        cnt++;
                }
                else if(s[i]=='0' and s[i-1]!='0'){
                    zero=0;
                    zero++;
                    if(one>=zero)
                        cnt++;
                }
                 
                else if(s[i]=='1' and s[i-1]=='1'){
                    one++;
                    if(one<=zero)
                        cnt++;
                }
                else if(s[i]=='1' and s[i-1]!='1'){
                    one=0;
                    one++;
                    if(one<=zero)
                        cnt++;
                }   
            }
        }
        
        return cnt;
    }
};