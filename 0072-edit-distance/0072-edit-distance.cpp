class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        // We only need a 1D array of size n + 1
        vector<int> dp(n + 1, 0);
        
        // Initialize base case: converting an empty word1 to word2 takes j insertions
        for (int j = 0; j <= n; j++) {
            dp[j] = j;
        }
        
        for (int i = 1; i <= m; i++) {
            // 'prev' stores the value of dp[i-1][j-1] (the top-left diagonal)
            int prev = dp[0]; 
            
            // Base case for the current row: converting word1 of length i to empty word2 takes i deletions
            dp[0] = i; 
            
            for (int j = 1; j <= n; j++) {
                // Store the current dp[j] (which acts as the 'top' cell for this iteration) 
                // before we overwrite it, so it can be used as 'prev' in the next iteration.
                int temp = dp[j]; 
                
                if (word1[i - 1] == word2[j - 1]) {
                    // Match: carry over the diagonal value
                    dp[j] = prev;
                } else {
                    // No match: take the minimum of Insert, Delete, and Replace
                    dp[j] = 1 + min({
                        dp[j - 1], // Insert (left cell, already updated for current row)
                        dp[j],     // Delete (top cell, not yet updated)
                        prev       // Replace (top-left diagonal)
                    });
                }
                
                // Update 'prev' to act as the diagonal for the next column (j+1)
                prev = temp; 
            }
        }
        
        return dp[n];
    }
};