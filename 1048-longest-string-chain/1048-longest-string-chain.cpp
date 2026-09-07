class Solution {
public:
    static bool compareLength(const string& a, const string& b) {
        return a.length() < b.length();
    }

    int longestStrChain(vector<string>& words) {
       
        sort(words.begin(), words.end(), compareLength);
        
        unordered_map<string, int> dp;
        int max_chain = 1;
        
        
        for (const string& word : words) {
            dp[word] = 1; 
            for (int i = 0; i < word.length(); ++i) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
               
                if (dp.find(predecessor) != dp.end()) {
                    dp[word] = max(dp[word], dp[predecessor] + 1);
                }
            }
           
            max_chain = max(max_chain, dp[word]);
        }
        
        return max_chain;
    }
};