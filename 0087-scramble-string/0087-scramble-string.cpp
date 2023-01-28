class Solution {
public:
    unordered_map<string,bool> mp;
    bool findSol(string s1,string s2){
        if(s1==s2)
            return true;
        int n=s1.size();
        if(n<=1)
            return false;
        if(mp.find(s1+s2)!=mp.end())
            return mp[s1+s2];
        
        for(int i=1;i<n;i++){
            bool op1=findSol(s1.substr(0,i),s2.substr(0,i)) && findSol(s1.substr(i),s2.substr(i));
            bool op2=findSol(s1.substr(0,i),s2.substr(n-i)) && findSol(s1.substr(i),s2.substr(0,n-i));
            if(op1 or op2)
                return true;
        }
        return mp[s1+s2]=false;
    }
    
    bool isScramble(string s1, string s2) {
        return findSol(s1,s2);
    }
};