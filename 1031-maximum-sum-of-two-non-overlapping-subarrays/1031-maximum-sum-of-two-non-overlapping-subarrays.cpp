class Solution {
public:
    int findSol(vector<int>& nums, int firstLen, int secondLen){
        int n=nums.size();
        vector<int> left(n,0),right(n,0);
        int sum=0,res=0;
        for(int i=0;i<n;i++){
            if(i<firstLen-1)
                sum+=nums[i];
            else if(i==firstLen-1){
                sum+=nums[i];
                left[i]=sum;
            }
            else{
                sum+=nums[i];
                sum-=nums[i-firstLen];
                left[i]=max(left[i-1],sum);
            }
        }
        
        sum=0;
        for(int i=n-1;i>=0;i--){
            if(i>n-secondLen)
                sum+=nums[i];
            else if(i==n-secondLen){
                sum+=nums[i];
                right[i]=sum;
            }
            else{
                sum+=nums[i];
                sum-=nums[i+secondLen];
                right[i]=max(right[i+1],sum);
            }
        }
        
        for(int i=0;i<n-1;i++){
            res=max(res,left[i]+right[i+1]);
        }
        return res;
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(findSol(nums,firstLen,secondLen),findSol(nums,secondLen,firstLen));
    }
};