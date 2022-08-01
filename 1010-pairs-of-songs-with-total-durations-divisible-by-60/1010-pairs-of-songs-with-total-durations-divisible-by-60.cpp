class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> rem(60,0);
        int res=0,n=time.size();
        for(int i=0;i<n;i++){
            int temp=time[i]%60;
            if(temp==0)
                res+=rem[0];
            else
                res+=rem[60-temp];
            rem[temp]++;
        }
        return res;
    }
};