class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(minSt.empty() == true || minSt.top().first > x) {
            minSt.push(make_pair(x,1));
        } else if(minSt.top().first == x) {
            (minSt.top().second)++;
        }
        st.push(x);
    }
    
    void pop() {
        if(minSt.top().first == st.top()) {
            (minSt.top().second)--;
            if(minSt.top().second == 0) {
                minSt.pop();
            }
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top().first;
    }
private:
    stack<int> st;
    stack< pair<int,int> > minSt;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
