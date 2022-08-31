class Solution {
public:
    void findSol(string str,int ind,string temp,unordered_set<string> &s1,vector<string> &res){
        if(ind==str.size()){
            temp.pop_back();
            res.push_back(temp);
            return;
        }
        string var="";
        for(int i=ind;i<str.size();i++){
            var+=str[i];
            if(s1.count(var)==1){
                temp+=var;
                temp+=' ';
                findSol(str,i+1,temp,s1,res);
                temp.pop_back();
                temp.erase(temp.size()-var.size());
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set s1(wordDict.begin(),wordDict.end());
        string temp="";
        vector<string> res;
        findSol(s,0,temp,s1,res);
        return res;
    }
};