class MinStack {
public:
    stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int value) {
        int minval=getMin();
        if(st.empty()|| minval>value){
            minval=value;
        }
        st.push({value,minval});
        
    }
    
    void pop() {
        st.pop();
        
    }
    
    int top() {
        return st.empty()?-1:st.top().first;
    }
    
    int getMin() {
        return st.empty()?-1:st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */