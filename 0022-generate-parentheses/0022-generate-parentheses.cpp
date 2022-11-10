class Solution {
public:
    void findSol(string str,int open,int close,int n,vector<string> &res){
        if(open>n or close>n or close>open)
            return;
        if(open==close and close==n){
            res.push_back(str);
            return;
        }
        findSol(str+'(',open+1,close,n,res);
        findSol(str+')',open,close+1,n,res);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str="";
        str+='(';
        findSol(str,1,0,n,res);
        return res;
    }
};