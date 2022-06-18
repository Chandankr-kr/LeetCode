class WordFilter {
public:
    unordered_map<string,int> mp;
    WordFilter(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++){
            string str=words[i];
            int t=str.size();
            for(int j=0;j<t;j++){
                string str1=str.substr(0,j+1);
                str1+="&";
                for(int k=0;k<t;k++){
                    string str2=str1+str.substr(k,t);
                    mp[str2]=i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        int res=-1;
        for(auto& it:mp){
            if(mp.find(prefix+"&"+suffix)!=mp.end())
                return mp[prefix+"&"+suffix];
        }
        return res;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */