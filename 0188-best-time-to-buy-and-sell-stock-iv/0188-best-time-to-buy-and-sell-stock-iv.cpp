class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        // The capacity dimension size changes from 3 (which was for k=2) to k + 1
        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                // Loop capacity up to k instead of 2
                for(int cap = 1; cap <= k; cap++) {
                    
                    int profit = 0;
                    if (buy) {
                        profit = max(-prices[i] + ahead[0][cap], 
                                      0 + ahead[1][cap]);
                    } else {
                        profit = max(prices[i] + ahead[1][cap - 1], 
                                      0 + ahead[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            ahead = curr; 
        }
        
        // Return the starting state with k transactions allowed
        return ahead[1][k];
    }
};