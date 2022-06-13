class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int res=0,maxi,mini,n=nums.size();
        if(nums[0]<0){
            maxi=0;
            mini=1;
        }
        else if(nums[0]>0){
            maxi=1;
            mini=0;
        }
        else{
            maxi=0;
            mini=0;
        }
        res=maxi;
        for(int i=1;i<n;i++){
            int tempMin,tempMax;
            if(nums[i]>0){
                tempMin=mini>0?1+mini:0;
                tempMax=maxi+1;
            }
            else if(nums[i]<0){
                tempMin=maxi+1;
                tempMax=mini>0?mini+1:0;
            }
            else{
                tempMax=0;
                tempMin=0;
            }
            maxi=tempMax;
            mini=tempMin;
            res=max(res,maxi);
        }        
        return res; 
    }
};