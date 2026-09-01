class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0; // Minimum possible open left parenthesis
        int cmax = 0; // Maximum possible open left parenthesis

        for (char c : s) {
            if (c == '(') {
                cmax++;
                cmin++;
            } else if (c == ')') {
                cmax--;
                cmin--;
            } else if (c == '*') {
                cmax++; // Treat '*' as '('
                cmin--; // Treat '*' as ')'
            }
            
            // If cmax is negative, it means there are too many ')' that cannot be matched
            if (cmax < 0) return false;
            
            // cmin cannot be negative. If it drops below 0, it means we tried to treat 
            // too many '*' as ')'. We must treat them as empty strings or '(' instead.
            cmin = max(cmin, 0); 
        }

        // The string is valid if we can achieve exactly 0 open parentheses at the end
        return cmin == 0;
    }
};