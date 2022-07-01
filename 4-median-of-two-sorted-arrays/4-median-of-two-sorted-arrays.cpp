class Solution {
public:
    double solve(vector<int>&A,vector<int>&B)
    {
        int n1=A.size(),n2=B.size(),total=n1+n2,half=total/2;
        int left=0,right=n1;
        while(left<=right)
        {
            int idxA=left+(right-left)/2;
            int idxB=(n1+n2)/2-idxA;
        
            //median
            int leftA=idxA>0?A[idxA-1]:INT_MIN;
            int rightA=idxA<n1?A[idxA]:INT_MAX;
            int leftB=idxB>0?B[idxB-1]:INT_MIN;
            int rightB=idxB<n2 ? B[idxB]:INT_MAX;
            if(leftA<=rightB && leftB<=rightA)
            {
                if(total&1)
                    return min(rightA,rightB);
                return (max(leftA,leftB)+min(rightA,rightB))/2.0;
            }
            else if(leftA>rightB)
                right=idxA-1;
            else
              left=idxA+1;
        }
                               
        return 0;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size())
            return solve(nums1,nums2);
        return solve(nums2,nums1);
        
    }
};