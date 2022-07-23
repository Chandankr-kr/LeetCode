class Solution {
public:
    void merge(vector<pair<int,int>> &nums,int lo,int mid,int hi,vector<int> &res){
        vector<pair<int,int>> temp(hi-lo+1);
        int i=lo,j=mid+1,cnt=0,k=0;
        
        while(i<=mid and j<=hi){
            if(nums[i].first<=nums[j].first){
                res[nums[i].second]+=cnt;
                temp[k++]=nums[i];
                i++;
            }
            else{
                cnt++;
                temp[k++]=nums[j];
                j++;
            }
        }
        
        while(i<=mid){
            res[nums[i].second]+=cnt;
            temp[k++]=nums[i];
            i++;
        }
        
        while(j<=hi){
            temp[k++]=nums[j];
            j++;
        }
        
        for(int i=lo;i<=hi;i++){
            nums[i]=temp[i-lo];
        }
    }
    
    void mergeSort(vector<pair<int,int>> &temp,int lo,int hi,vector<int> &res){
        if(lo<hi){
            int mid=lo+(hi-lo)/2;
            mergeSort(temp,lo,mid,res);
            mergeSort(temp,mid+1,hi,res);
            merge(temp,lo,mid,hi,res);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0);
        vector<pair<int,int>> temp;
        int lo=0,hi=nums.size()-1;
        for(int i=0;i<=hi;i++){
            temp.push_back({nums[i],i});
        }
        mergeSort(temp,lo,hi,res);
        return res;
    }
};