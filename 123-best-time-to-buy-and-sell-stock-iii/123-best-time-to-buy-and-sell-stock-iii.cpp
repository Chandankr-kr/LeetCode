class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),result=0;
        vector<int> left,right;
        int temp=0,res=0;
        for(int i=0;i<n;i++){
            if(prices[i]<prices[temp])
                temp=i;
            else
                res=max(res,prices[i]-prices[temp]);
            left.push_back(res);
        }
        
        temp=n-1,res=0;
        for(int i=n-1;i>=0;i--){
            if(prices[i]>prices[temp])
                temp=i;
            else
                res=max(res,prices[temp]-prices[i]);
            right.push_back(res);
        }
        reverse(right.begin(),right.end());
        for(int i=0;i<n;i++){
            result=max(result,left[i]+right[i]);
        }
        return result;
    }
};