#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // last_pos[j] stores the maximum starting index in word1 
        // to match suffix of word2 starting from index j.
        vector<int> last_pos(m + 1, -1);
        last_pos[m] = n;
        
        int p2 = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (p2 >= 0 && word1[i] == word2[p2]) {
                last_pos[p2] = i;
                p2--;
            }
        }
        
        vector<int> ans;
        bool used_change = false;
        p2 = 0;
        
        for (int i = 0; i < n && p2 < m; ++i) {
            bool is_match = (word1[i] == word2[p2]);
            
            if (is_match) {
                ans.push_back(i);
                p2++;
            } else if (!used_change && last_pos[p2 + 1] > i) {
                // Greedily use the allowed 1 character change
                ans.push_back(i);
                used_change = true;
                p2++;
            }
        }
        
        return ans.size() == m ? ans : vector<int>();
    }
};