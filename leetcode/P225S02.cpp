class Stack {
public:
    queue<int> q1;
    queue<int> q2;
    int Top;
    // Push element x onto stack.
    void push(int x) {
        Top = x;
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        auto tmp = q1;
        q1 = q2;
        q2 = tmp;
    }

    // Removes the element on top of the stack.
    void pop() {
        q1.pop();
        Top = q1.front();
    }

    // Get the top element.
    int top() {
        return Top;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};
