class Solution {
public:
    int cnt;
    void merge(vector<int>& nums,int lo,int mid,int hi){
        int i=lo,j=mid+1;
        while(i<=mid and j<=hi){
            if((long long int)nums[i]>(long long int)2*nums[j]){
                j++;
                cnt+=mid-i+1;
            }
            else{
                i++;
            }
        }
        
        sort(nums.begin()+lo,nums.begin()+hi+1);
    }
    
    void mergeSort(vector<int>& nums,int lo,int hi){
        if(lo<hi){
            int mid=lo+(hi-lo)/2;
            mergeSort(nums,lo,mid);
            mergeSort(nums,mid+1,hi);
            merge(nums,lo,mid,hi);
        }
    }
    
    int reversePairs(vector<int>& nums) {
        cnt=0;
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return cnt;
    }
};