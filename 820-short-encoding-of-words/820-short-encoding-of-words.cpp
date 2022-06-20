class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s1;
        int cnt=0;
        for(auto &it:words){
            s1.insert(it);
        }
        
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                if(s1.find(words[i].substr(j+1))!=s1.end())
                    s1.erase(words[i].substr(j+1));
            }
        }
        
        for(auto &it:s1){
            cnt+=it.size()+1;
        }
        return cnt;
    }
};