class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            swap(nums1,nums2);
        int m=nums1.size(),n=nums2.size();
        int lo=0,hi=m;
        while(lo<=hi){
            int m1=(lo+hi)/2;
            int m2=(m+n)/2-m1;
            
            int l1=m1==0?INT_MIN:nums1[m1-1];
            int r1=m1==m?INT_MAX:nums1[m1];
            
            int l2=m2==0?INT_MIN:nums2[m2-1];
            int r2=m2==n?INT_MAX:nums2[m2];
            
            if(l1>r2)
                hi=m1-1;
            else if(r1<l2)
                lo=m1+1;
            else{
                if((m+n)%2)
                    return min(r1,r2)/1.0;
                else
                    return (max(l1,l2)+min(r1,r2))/2.0;
            }
        }
        return -1;
    }
};