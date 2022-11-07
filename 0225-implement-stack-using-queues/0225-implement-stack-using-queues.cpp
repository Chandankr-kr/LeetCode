class MyStack {
public:
    queue<int> q1,q2;
    
    void push(int x) {
        while(q1.size()){
            q1.pop();
        }
        q1.push(x);
        while(q2.size()){
            q1.push(q2.front());
            q2.pop();
        }
        q2=q1;
    }
    
    int pop() {
        int k=q2.front();
        q2.pop();
        return k;
    }
    
    int top() {
        return q2.front();
    }
    
    bool empty() {
        if(q2.size()==0)
            return true;
        else
            return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */