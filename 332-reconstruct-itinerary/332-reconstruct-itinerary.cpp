class Solution {
public:
    map<string,multiset<string>> mp;
    vector<string> res;
    
    void findSol(string str){
        while(mp[str].size()){
            string temp=*mp[str].begin();
            mp[str].erase(mp[str].begin());
            findSol(temp);
        }
        res.push_back(str);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto it:tickets){
            mp[it[0]].insert(it[1]);
        }
        findSol("JFK");
        reverse(res.begin(),res.end());
        return res;
    }
};