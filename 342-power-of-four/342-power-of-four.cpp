class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)
            return true;
        long long int res=1;
        while(res<=n){
            res=res<<2;
            if(res==n)
                return true;
        }
        return false;
    }
};