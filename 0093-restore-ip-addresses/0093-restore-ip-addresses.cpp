void findRes(string s,int index,int step,vector<string> &res,string str)
    {
    //cout<<s.size()<<" ";
    //cout<<index<<" ";
    if(index==s.size() && step==4)
    {
        str.erase(str.size()-1);
        cout<<str<<" ";
        res.push_back(str);
        return;
    }
    
    if((s.size()-index)>(4-step)*3)
       return;
    if((s.size()-index)<(4-step))
        return;
    
    int num=0;
    for(int i=index;i<index+3;i++)
    {
        num=num*10+(s[i]-'0');
        if(num<=255)
        {
            str=str+s[i];
            findRes(s,i+1,step+1,res,str+'.');
        }
        if(num==0)
            break;
    }
}

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string str="";
        findRes(s,0,0,res,str);
        return res;
    }
};