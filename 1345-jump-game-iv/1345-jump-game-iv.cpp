class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        int n=arr.size(),res=0;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<bool> visited(n,false);
        queue<int> q1;
        q1.push(0);
        visited[0]=true;
        while(q1.size()){
            int t=q1.size();
            for(int i=0;i<t;i++){
                int j=q1.front();
                q1.pop();
                if(j==n-1)
                    return res;
                vector<int> &temp=mp[arr[j]];
                temp.push_back(j-1);
                temp.push_back(j+1);
                for(auto &it:temp){
                    if(it>0 and it<n and visited[it]==false){
                        visited[it]=true;
                        q1.push(it);
                    }
                }
                temp.clear();
            }
            res++;
        }
        return 0;
    }
};