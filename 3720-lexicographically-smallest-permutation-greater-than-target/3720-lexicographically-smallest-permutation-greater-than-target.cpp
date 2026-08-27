#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> counts(26, 0);
        
        // Count character frequencies in s
        for (char c : s) {
            counts[c - 'a']++;
        }
        
        int match_len = 0;
        vector<int> current_counts = counts;
        
        // Find how far we can perfectly match the target
        for (int i = 0; i < n; i++) {
            if (current_counts[target[i] - 'a'] > 0) {
                current_counts[target[i] - 'a']--;
                match_len++;
            } else {
                break;
            }
        }
        
        // Try to diverge at the rightmost possible index
        for (int i = min(n - 1, match_len); i >= 0; i--) {
            // If we are looking at an index that was successfully matched before,
            // we must 'unmatch' it and add the character back to our available pool.
            if (i < match_len) {
                current_counts[target[i] - 'a']++;
            }
            
            // Try to find the smallest character strictly greater than target[i]
            int best_char = -1;
            for (int c = (target[i] - 'a') + 1; c < 26; c++) {
                if (current_counts[c] > 0) {
                    best_char = c;
                    break;
                }
            }
            
            // If we found a valid character to diverge, build the final string
            if (best_char != -1) {
                string res = target.substr(0, i); // Keep the exact prefix match
                res += (char)(best_char + 'a');   // Append the strictly greater character
                current_counts[best_char]--;
                
                // Append all remaining available characters in ascending order
                for (int c = 0; c < 26; c++) {
                    while (current_counts[c] > 0) {
                        res += (char)(c + 'a');
                        current_counts[c]--;
                    }
                }
                return res;
            }
        }
        
        // If no valid permutation is strictly greater, return an empty string
        return "";
    }
};