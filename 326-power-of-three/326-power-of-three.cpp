class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)
            return false;
        long temp=1;
        while(temp<n){
            temp*=3;
        }
        return temp==n;
    }
};