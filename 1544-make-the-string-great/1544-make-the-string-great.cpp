class Solution {
public:
    string makeGood(string s) {
        string str="";
    for(auto c:s)
    {
        if(str.size()>0 and str.back()!=c and tolower(str.back())==tolower(c))
            str.pop_back();
        else
            str+=c;
    }
        return str;
    }
};