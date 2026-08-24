class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        
        // Calculate the total sum of the array which is prefix[n-1]
        int current_prefix_sum = 0;
        for (int stone : stones) {
            current_prefix_sum += stone;
        }
        
        // Base case: if the player is forced to take all remaining stones
        int dp = current_prefix_sum;
        
        // Iterate backwards from the second to last index down to 1
        // (Index 0 is not allowed because a player must take x > 1 stones)
        for (int i = n - 2; i >= 1; --i) {
            current_prefix_sum -= stones[i + 1]; // Update to get prefix[i]
            
            // Player maximizes their score: either they pick this prefix sum and 
            // subtract the opponent's optimal future score, or they skip and defer to the next optimal choice.
            dp = max(dp, current_prefix_sum - dp);
        }
        
        return dp;
    }
};