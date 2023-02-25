class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX;
        int p=0;
        for(int i=0;i<prices.size();i++)
        {
            if(min>prices[i])
                min=prices[i];
            if((prices[i]-min)>p)
                p=prices[i]-min;
        }
        return p; 
    }
};