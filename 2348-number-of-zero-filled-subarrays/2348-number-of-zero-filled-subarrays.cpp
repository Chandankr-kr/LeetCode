class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<long long int>  res;
        long long int n=nums.size(),t=0;
        long long int result=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                t++;
            }
            else{
                if(t!=0){
                    res.push_back(t);
                }
                t=0;
            }
        }
        if(t!=0)
            res.push_back(t);
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<res.size();i++){
            result+=(res[i]*(res[i]+1))/2;
        }
        return result;
    }
};