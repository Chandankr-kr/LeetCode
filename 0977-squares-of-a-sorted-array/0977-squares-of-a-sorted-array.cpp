class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size(),k=0,j=n;
        vector<int> res;
        
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                j=i;
                break;
            }
        }
        
        if(j>0){
            k=j-1;
        }
        else{
            k=-1;
        }
        
        while(k>=0 and j<n){
            int a=nums[k]*nums[k];
            int b=nums[j]*nums[j];
            if(a<b){
                res.push_back(a);
                k--;
            }
            else{
                res.push_back(b);
                j++;
            }
        }
        
        while(k>=0){
            int a=nums[k]*nums[k];
            res.push_back(a);
                k--;
        }
        
        while(j<n){
            int b=nums[j]*nums[j];
            res.push_back(b);
                j++;
        }
        
        return res;
    }
};