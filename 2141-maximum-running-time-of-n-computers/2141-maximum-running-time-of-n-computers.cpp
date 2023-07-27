class Solution {
public:
    bool findSol(vector<int> &batteries,long long int cnt,int n){
        long long sum=0;
        for(int i=0;i<batteries.size();i++){
            if(batteries[i]>=cnt)
                sum+=cnt;
            else
                sum+=batteries[i];
        }
        return sum>=cnt*n;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        long long int sum=0;
        for(auto it:batteries)
            sum+=it;
        long long int lo=0,hi=sum;
        long long ans=0;
        while(lo<=hi){
            long long int mid=lo+(hi-lo)/2;
            bool res=findSol(batteries,mid,n);
            if(res){
                lo=mid+1;
                ans=mid;
            }
            else
                hi=mid-1;
        }
        return ans;
    }
};