class Stack {
public:
    queue<int> q;
    int Top;
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        Top = x;
        int size = q.size();
        while(size > 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
        Top = q.front();
    }

    // Get the top element.
    int top() {
        return Top;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};
