class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> s1;
        int n=s.size();
        vector<int> res(n+1,false);
        res[0]=true;
        for(auto &it:wordDict){
            s1.insert(it);
        }
        
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(res[j]){
                    string str=s.substr(j,i-j);
                    if(s1.find(str)!=s1.end()){
                        res[i]=true;
                        break;
                    }
                }
            }
        }
        return res[n];
    }
};