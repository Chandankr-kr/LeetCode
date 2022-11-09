class StockSpanner {
public:
    stack<pair<int,int>> s1;
    
    int next(int price) {
        int cnt=1;
        while(s1.size() and s1.top().first<=price){
            cnt+=s1.top().second;
            s1.pop();
        }
        s1.push({price,cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */