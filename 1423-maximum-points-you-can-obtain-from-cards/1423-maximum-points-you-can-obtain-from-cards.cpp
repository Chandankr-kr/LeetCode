class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int> left(n,0),right(n,0);
        left[0]=cardPoints[0];
        right[n-1]=cardPoints[n-1];
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+cardPoints[i];
        }
        
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]+cardPoints[i];
        }
        int res=max(left[k-1],right[n-k]);
        
        int i=k-2,j=n-1;
        k=k-1;
        while(k--){
            res=max(res,left[i]+right[j]);
            i--,j--;
        }
        return res;
    }
};