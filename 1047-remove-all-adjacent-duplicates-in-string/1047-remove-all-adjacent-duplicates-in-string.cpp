class Solution {
public:
    string removeDuplicates(string s) {
        string res="";
        for(auto str:s){
            if(res=="")
                res+=str;
            else if(res.back()==str)
                res.pop_back();
            else
                res+=str;
        }
        return res;
    }
};