#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int dp[4] = {0, 0, 0, 0};

        for (int i = n - 1; i >= 0; i--) {
            int takeOne = stoneValue[i] - dp[(i + 1) % 4];
            
            int takeTwo = INT_MIN;
            if (i + 1 < n) {
                takeTwo = stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) % 4];
            }

            int takeThree = INT_MIN;
            if (i + 2 < n) {
                takeThree = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[(i + 3) % 4];
            }

            dp[i % 4] = max({takeOne, takeTwo, takeThree});
        }

        int diff = dp[0];
        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};