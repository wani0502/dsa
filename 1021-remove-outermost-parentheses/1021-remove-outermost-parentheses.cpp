class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int opened = 0;
        
        for (char c : s) {
            if (c == '(') {
                // If it's strictly greater than 0, it's an inner parenthesis
                if (opened > 0) {
                    result += c;
                }
                opened++;
            } else if (c == ')') {
                opened--;
                // If it's strictly greater than 0 after decrementing, it's an inner parenthesis
                if (opened > 0) {
                    result += c;
                }
            }
        }
        
        return result;
    }
};