#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
    int memo[101][101];
    
    int solve(int i, int M, vector<int>& piles, vector<int>& suffixSum) {
        int n = piles.size();
        
        // Base case: If we can take all remaining piles, take them all
        if (i + 2 * M >= n) {
            return suffixSum[i];
        }
        
        if (memo[i][M] != 0) {
            return memo[i][M];
        }
        
        int maxStones = 0;
        
        // Try taking X piles where 1 <= X <= 2 * M
        for (int X = 1; X <= 2 * M; ++X) {
            // Remaining stones - opponent's optimal choice from the remaining piles
            int currentStones = suffixSum[i] - solve(i + X, max(M, X), piles, suffixSum);
            maxStones = max(maxStones, currentStones);
        }
        
        return memo[i][M] = maxStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n, 0);
        
        // Compute suffix sums for O(1) remaining stone lookup
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        return solve(0, 1, piles, suffixSum);
    }
};