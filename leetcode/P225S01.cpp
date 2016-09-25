class Stack {
public:
    queue<int> q1;
    queue<int> q2;
    int Top;
    
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
        Top = x;
    }

    // Removes the element on top of the stack.
    void pop() {
        while(q1.size() > 1) {
            Top = q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        auto tmp = q1;
        q1 = q2;
        q2 = tmp;
    }

    // Get the top element.
    int top() {
        return Top;
    }

    // Return whether the stack is empty.
    bool empty() {
        if(q1.empty())
            return true;
        return false;
    }
};
