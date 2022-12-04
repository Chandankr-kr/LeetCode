class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        string res="";
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        vector<pair<int,char>> v1;
        for(auto it:mp){
            v1.push_back({it.second,it.first});
        }
        sort(v1.begin(),v1.end());
        reverse(v1.begin(),v1.end());
        
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v1[i].first;j++){
                res+=v1[i].second;
            }
        }
        return res;
    }
};