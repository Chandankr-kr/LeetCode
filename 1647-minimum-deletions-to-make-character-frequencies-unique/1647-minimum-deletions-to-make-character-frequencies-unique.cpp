class Solution {
public:
    int minDeletions(string s) {
        vector<int> res(26,0);
        for(int i=0;i<s.size();i++){
            res[s[i]-'a']++;
        }
        
        int cnt=0;
        unordered_set<int> s1;
        for(int i=0;i<26;i++){
            while(res[i] and s1.find(res[i])!=s1.end()){
                res[i]--;
                cnt++;
            }
            s1.insert(res[i]);
        }
        return cnt;
    }
};