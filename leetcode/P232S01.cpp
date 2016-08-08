class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        while(st.empty() == false) {
            dupSt.push(st.top());
            st.pop();
        }
        st.push(x);
        while(dupSt.empty() == false) {
            st.push(dupSt.top());
            dupSt.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        st.pop();
    }

    // Get the front element.
    int peek(void) {
        return st.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st.empty();
    }
private:
    stack<int> st;
    stack<int> dupSt;
};
