class Solution {
public:
    static bool compare(const string& str1,const string& str2){
        return str1.size()<str2.size();    
    }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size(),res=0;
        unordered_map<string,int> mp;
        sort(words.begin(),words.end(),compare);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                string str=words[i].substr(0,j)+words[i].substr(j+1);
                mp[words[i]]=max(mp[words[i]],mp.find(str)==mp.end()?1:1+mp[str]);
            }
            res=max(res,mp[words[i]]);
        }
        return res;
    }
};