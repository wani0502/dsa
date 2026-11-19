class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;
        for (int stone : stones) {
            total += stone;
        }
        int target = total / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int sum = 0; sum <= target; sum++) {
            if (stones[0] <= sum) {
                dp[0][sum] = stones[0];
            }
        }
        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= target; sum++) {
                // Do not take
                int notTake = dp[i - 1][sum];
                // Take
                int take = 0;
                if (stones[i] <= sum) {
                    take = stones[i] + dp[i - 1][sum - stones[i]];
                }
                dp[i][sum] = max(take, notTake);
            }
        }
        int s1 = dp[n - 1][target];
        return total - 2 * s1;
    }
};