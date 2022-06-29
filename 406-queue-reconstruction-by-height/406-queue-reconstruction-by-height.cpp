class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        sort(people.begin(),people.end());
        vector<vector<int>> res(n,vector<int> (2,-1));
        for(int i=0;i<n;i++)
        {
            int cnt=people[i][1];
            for(int j=0;j<n;j++)
            {
                if(cnt==0 && res[j][1]==-1)
                {
                    res[j]=people[i];
                    break;
                }
                else if(res[j][1]==-1 || res[j][0]>=people[i][0])
                    cnt--;
            }
        }
        return res;
    }
};