class MinStack {
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() {
    }
    
    void push(int value) {
        long long val = value;
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val >= mini) {
                st.push(val);
            } else {
                // Encode the previous minimum into the stack
                st.push(2 * val - mini);
                mini = val; // Update the new minimum
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        
        long long top = st.top();
        st.pop();
        
        // If top is less than mini, it means this element was a flag for a new minimum.
        // We need to decode and rollback to the previous minimum.
        if (top < mini) {
            mini = 2 * mini - top;
        }
    }
    
    int top() {
        long long top = st.top();
        // If the top value is less than mini, it's an encoded value, 
        // and the actual value that was pushed is stored in 'mini'.
        if (top < mini) {
            return mini;
        }
        return top;
    }
    
    int getMin() {
        return mini;
    }
};