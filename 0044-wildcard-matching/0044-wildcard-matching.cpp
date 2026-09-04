class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        // 1D array to store the current row of the DP table
        vector<bool> dp(n + 1, false);
        
        // Base case: empty string matches empty pattern
        dp[0] = true;
        
        // Initialize for empty string `s` but non-empty pattern `p`
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[j] = dp[j - 1];
            }
        }
        
        // Fill the DP array
        for (int i = 1; i <= m; i++) {
            bool prev = dp[0]; // Stores the diagonal value dp[i-1][j-1]
            dp[0] = false;     // A non-empty string cannot match an empty pattern
            
            for (int j = 1; j <= n; j++) {
                bool temp = dp[j]; // Store current top value before overwriting
                
                if (p[j - 1] == '*') {
                    // Match 0 characters (dp[j-1]) OR match 1+ characters (dp[j])
                    dp[j] = dp[j - 1] || dp[j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    // Match single character, take the diagonal
                    dp[j] = prev;
                } else {
                    dp[j] = false;
                }
                
                prev = temp; // Update diagonal for the next column
            }
        }
        
        return dp[n];
    }
};