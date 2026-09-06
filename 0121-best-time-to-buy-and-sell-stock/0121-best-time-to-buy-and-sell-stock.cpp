class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // 'ahead' represents dp[i + 1]
        // 'curr' represents dp[i]
        vector<int> ahead(2, 0);
        vector<int> curr(2, 0);
        
        // Loop backwards from n-1 down to 0
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                
                int profit = 0;
                if (buy == 1) {
                    // Option 1: Buy today (transition to buy=0)
                    // Option 2: Skip today (keep buy=1)
                    profit = max(-prices[i] + ahead[0], 0 + ahead[1]);
                } else {
                    // Option 1: Sell today (finish, 0 future profit)
                    // Option 2: Skip today (keep buy=0)
                    profit = max(prices[i] + 0, 0 + ahead[0]);
                }
                
                curr[buy] = profit;
            }
            // Move the current day's calculations to 'ahead' for the next iteration
            ahead = curr; 
        }
        
        // Return the result starting with permission to buy
        return ahead[1];
    }
};