class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // Use std::set to avoid worst-case hash collision TLEs
        set<int> s(nums.begin(), nums.end());
        
        int longestConsecutiveSequence = 0;
        
        for (int num : s) {
            // Check if it's the start of a sequence
            if (s.find(num - 1) == s.end()) {
                int currentNumber = num;
                int currentConsecutiveSequence = 1;
                
                while (s.find(currentNumber + 1) != s.end()) {
                    currentNumber++;
                    currentConsecutiveSequence++;
                }
                
                longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
            }
        }
        
        return longestConsecutiveSequence;
    }
};