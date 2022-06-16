class Solution {
public:
    int numberOfSubstrings(string s) {
        int res=0,n=s.size(),j=0;
        unordered_map<char,int> mp;
        mp['a']=0,mp['b']=0,mp['c']=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp['a'] and mp['b'] and mp['c']){
                mp[s[j++]]--;
            }
            res+=j;
        }
        return res;
    }
};