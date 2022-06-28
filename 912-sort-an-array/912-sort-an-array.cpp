class Solution {
public:
    void merge(vector<int> &nums,int lo,int mid,int hi){
        vector<int> temp(hi-lo+1);
        int i=lo,j=mid+1,k=0;
        while(i<=mid and j<=hi){
            if(nums[i]<nums[j]){
                temp[k++]=nums[i++];
            }
            else{
                temp[k++]=nums[j++];
            }
        }
        
        while(i<=mid){
            temp[k++]=nums[i++];
        }
        
        while(j<=hi){
            temp[k++]=nums[j++];
        }
        
        for(int i=lo;i<=hi;i++){
            nums[i]=temp[i-lo];
        }
    }
    
    void mergeSort(vector<int>& nums,int lo,int hi){
        if(lo<hi){
            int mid=lo+(hi-lo)/2;
            mergeSort(nums,lo,mid);
            mergeSort(nums,mid+1,hi);
            merge(nums,lo,mid,hi);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};