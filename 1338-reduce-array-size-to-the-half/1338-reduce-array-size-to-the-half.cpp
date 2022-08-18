class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq1;
        int res=0,n=arr.size(),cnt=0;
        
        for(auto &it:arr){
            mp[it]++;
        }
        
        for(auto &it:mp){
            pq1.push({it.second,it.first});
        }
        
        while(pq1.size()){
            auto it=pq1.top();
            pq1.pop();
            res+=it.first;
            cnt++;
            if(res>=n/2)
                break;
        }
        return cnt;
    }
};