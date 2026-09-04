class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        // dp[i][j] represents the minimum operations to convert 
        // the first i characters of word1 to the first j characters of word2.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Base case 1: word2 is empty, we must delete all characters in word1
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        
        // Base case 2: word1 is empty, we must insert all characters of word2
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        
        // Fill the DP table iteratively
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If the current characters match, carry over the previous diagonal value
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                // If they don't match, take the minimum of the 3 possible operations + 1
                else {
                    dp[i][j] = 1 + min({
                        dp[i][j - 1],    // Insert
                        dp[i - 1][j],    // Delete
                        dp[i - 1][j - 1] // Replace
                    });
                }
            }
        }
        
        return dp[m][n];
    }
};