class Solution {
public:
    void merge(vector<pair<int,int>> &nums,int lo,int mid,int hi,vector<int>& res){
        vector<pair<int,int>> temp(hi-lo+1);
        int i=lo,j=mid+1,k=0,cnt=0;
        
        while(i<=mid and j<=hi){
            if(nums[i].first<=nums[j].first){
                res[nums[i].second]+=cnt;
                temp[k++]=nums[i++];
            }
            else{
                cnt++;
                temp[k++]=nums[j++];
            }
        }
        
        while(i<=mid){
            res[nums[i].second]+=cnt;
            temp[k++]=nums[i++];
        }
        
        while(j<=hi){
            temp[k++]=nums[j++];
        }
        
        for(int i=lo;i<=hi;i++){
            nums[i]=temp[i-lo];
        }
    }
    
    void mergeSort(vector<pair<int,int>> &v1,int lo,int hi,vector<int> &res){
        if(lo<hi){
            int mid=lo+(hi-lo)/2;
            mergeSort(v1,lo,mid,res);
            mergeSort(v1,mid+1,hi,res);
            merge(v1,lo,mid,hi,res);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0);
        vector<pair<int,int>> v1;
        for(int i=0;i<n;i++){
            v1.push_back({nums[i],i});
        }
        mergeSort(v1,0,n-1,res);
        return res;
    }
};