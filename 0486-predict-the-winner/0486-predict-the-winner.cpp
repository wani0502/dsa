class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        // If length is even, Player 1 can always win or tie by picking odd/even strategy
        if (n % 2 == 0) return true;

        // dp[i] stores max score difference for subarray ending at j
        vector<int> dp = nums;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }

        return dp[n - 1] >= 0;
    }
};