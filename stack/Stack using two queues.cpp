//leetcode- 225

class MyStack {
public:
queue<int>q1;
queue<int>q2;

    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        while(q1.empty()) return -1;
        int top=q1.front();
        q1.pop();
        return top;
    }
    
    int top() {
        while(q1.empty()) return -1;
        return q1.front();
    }
    
    bool empty() {
        return q1.size()==0;
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