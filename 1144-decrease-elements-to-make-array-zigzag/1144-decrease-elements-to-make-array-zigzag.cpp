class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n=nums.size(),res=0,sum=0;
        vector<int> v1(nums);
        
        //  starting no is smaller
        for(int i=1;i<n;i++){
           if(i%2 and nums[i]<=nums[i-1]){
               sum+=nums[i-1]-(nums[i]-1);
               nums[i-1]=nums[i]-1;
           }
            
            if(i%2==0 and nums[i]>=nums[i-1]){
                sum+=nums[i]-(nums[i-1]-1);
                nums[i]=nums[i-1]-1;
            }
        }
        
        res=sum;
        sum=0;
        //  starting no is larger
        for(int i=1;i<n;i++){
            if(i%2 and v1[i]>=v1[i-1]){
                sum+=v1[i]-(v1[i-1]-1);
                v1[i]=v1[i-1]-1;
            }
            
            if(i%2==0 and v1[i]<=v1[i-1]){
                sum+=v1[i-1]-(v1[i]-1);
                v1[i-1]=v1[i]-1;
            }
        }
        return min(res,sum);
    }
};