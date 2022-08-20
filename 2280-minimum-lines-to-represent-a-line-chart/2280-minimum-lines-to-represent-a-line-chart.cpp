class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(),stockPrices.end());
        int n=stockPrices.size();
        if(n<=1)
            return 0;
        if(n<=2)
            return 1;
        int cnt=0;
        
        for(int i=2;i<n;i++){
            long long int x1 = stockPrices[i][0]-stockPrices[i-1][0];
            long long int x2 = stockPrices[i-1][0]-stockPrices[i-2][0];
            long long int y1 = stockPrices[i][1]-stockPrices[i-1][1];
            long long int y2 = stockPrices[i-1][1]-stockPrices[i-2][1];
            
            if(x1*y2!=x2*y1)
                cnt++;
        }
        return cnt+1;
    }
};