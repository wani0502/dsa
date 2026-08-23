class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sumL = 0, sumR = 0;
        int qL = 0, qR = 0;
        
        // Process the first half
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                qL++;
            } else {
                sumL += num[i] - '0';
            }
        }
        
        // Process the second half
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                qR++;
            } else {
                sumR += num[i] - '0';
            }
        }
        
        // If the total number of '?' is odd, Alice always gets the last move and wins.
        if ((qL + qR) % 2 != 0) {
            return true;
        }
        
        // If '?' is even, check if Bob can perfectly balance the sums
        return 2 * (sumL - sumR) != 9 * (qR - qL);
    }
};