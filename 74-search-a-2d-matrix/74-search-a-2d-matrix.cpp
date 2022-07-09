class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int lo=0,hi=m*n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int r=mid/n;
            int c=mid%n;
            if(matrix[r][c]==target)
                return true;
            else if(matrix[r][c]<target)
                lo=mid+1;
            else
                hi=mid-1;
        }
        return false;
    }
};