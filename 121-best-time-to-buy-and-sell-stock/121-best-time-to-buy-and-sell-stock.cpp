class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> res;
        int n=prices.size(),result=0;
        stack<int> s1;
        s1.push(prices[n-1]);
        res.push_back(prices[n-1]);
        
        for(int i=n-2;i>=0;i--){
            if(prices[i]>s1.top()){
                s1.pop();
                s1.push(prices[i]);
            }
            res.push_back(s1.top());
        }
        
        reverse(res.begin(),res.end());
        
        for(int i=0;i<n;i++){
            result=max(result,res[i]-prices[i]);
        }
        
        return result;
    }
};