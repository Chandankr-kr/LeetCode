class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long int> res;
        long long int n=nums.size(),sum=nums[0],result=INT_MAX,temp=0,t=0;
        res.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            sum+=nums[i];
            res.push_back(sum);
        }
        
        // for(int i=0;i<res.size();i++){
        //     cout<<res[i]<<" ";
        // }
        
        for(long long int i=0;i<n;i++){
            long long int k;
            if(n-i-1!=0)
                k=abs((res[i]/(i+1))-((res[n-1]-res[i])/(n-i-1)));
            else
                k=(res[i]/(i+1));
            // cout<<res[i]<<" "<<res[n-1]-res[i]<<" "<<i+1<<" "<<n-i-1<<endl;
            // cout<<k<<" ";
            if(k<result){
                result=k;
                t=i;
            }
        }
        return t;
    }
};