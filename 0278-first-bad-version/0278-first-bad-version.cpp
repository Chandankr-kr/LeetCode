// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo=0;
        int hi=n;
        if(isBadVersion(0))
            return 0;
        
        while(lo<=hi){
            int mid=((hi-lo)/2)+lo;
            if(isBadVersion(mid)==true and isBadVersion(mid-1)==false)
                return mid;
            else if(isBadVersion(mid))
                hi=mid-1;
            else
                lo=mid+1;
        }
        return lo;
    }
};