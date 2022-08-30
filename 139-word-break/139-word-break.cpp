class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> res(n+1,false);
        unordered_set<string> s1;
        for(auto &it:wordDict){
            s1.insert(it);
        }
        res[0]=true;
        
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(res[j]){
                    string str=s.substr(j,i-j);
                    if(s1.count(str)>0){
                        res[i]=true;
                        break;
                    }
                }
            }
        }
        return res[n];
    }
};