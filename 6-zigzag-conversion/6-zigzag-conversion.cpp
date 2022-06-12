class Solution {
public:
    string convert(string s, int n) {
        if(n<=1)
            return s;
        string str="";
        int cycle=2*n-2;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<s.size();j=j+cycle)
            {
                str=str+s[j];
                int oi=j+cycle-2*i;
                if(i!=0 && i!=n-1 && oi<s.size())
                {
                    str=str+s[oi];
                }
            }
        }
        return str;
    }
};