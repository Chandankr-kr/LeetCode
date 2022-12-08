class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        string str="11";
        int cnt=1;
        
        for(int i=3;i<=n;i++){
            string s1="";
            str+='*';
            for(int j=1;j<str.size();j++){
                if(str[j-1]==str[j]){
                    cnt++;
                }
                else{
                    s1+=cnt+'0';
                    s1+=str[j-1];
                    cnt=1;
                }
            }
            str=s1;
        }
        return str;
    }
};