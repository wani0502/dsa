class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        for (char digit : num) {
           
            while (k > 0 && !st.empty() && st.top() > digit) {
                st.pop();
                k--;
            }
          
            if (!st.empty() || digit != '0') {
                st.push(digit);
            }
        }
        
        // If we still need to remove digits (e.g., number was monotonically increasing)
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        // If stack is empty after all removals, return "0"
        if (st.empty()) {
            return "0";
        }
        
        // Build the final string from the stack
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        // Since a stack is LIFO, the characters are in reverse order
        reverse(result.begin(), result.end());
        
        return result;
    }
};