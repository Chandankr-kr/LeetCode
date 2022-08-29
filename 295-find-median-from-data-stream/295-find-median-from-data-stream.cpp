class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    
    void addNum(int num) {
        
        if(pq2.size()==0 or pq2.top()<num)
            pq2.push(num);
        else
            pq1.push(num);
        
        if(pq2.size()>pq1.size()+1){
            pq1.push(pq2.top());
            pq2.pop();
        }
        else if(pq1.size()>pq2.size()+1){
            pq2.push(pq1.top());
            pq1.pop();
        }
    }
    
    double findMedian() {
        if(pq1.size()==pq2.size())
            return (pq1.top()+pq2.top())/2.0;
        else if(pq1.size()>pq2.size())
            return (double)pq1.top();
        else 
            return (double)pq2.top(); 
    }
};
