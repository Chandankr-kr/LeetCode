class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            swap(nums1,nums2);
        
        int m=nums1.size();
        int n=nums2.size();
        int lo=0,hi=m;
        
        while(lo<=hi){
            int c1=(lo+hi)/2;
            int c2=(m+n)/2-c1;
            
            int l1=c1==0?INT_MIN:nums1[c1-1];
            int r1=c1==m?INT_MAX:nums1[c1];
            
            int l2=c2==0?INT_MIN:nums2[c2-1];
            int r2=c2==n?INT_MAX:nums2[c2];
            
            if(l1>r2)
                hi=c1-1;
            else if(r1<l2)
                lo=c1+1;
            else{
                if((m+n)%2==0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else
                    return min(r1,r2)/1.0;
            }
        }
        return -1;
    }
};