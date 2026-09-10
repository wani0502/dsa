class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Exactly K distinct = (At most K) - (At most K - 1)
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    
private:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int result = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            // Add current number to our frequency map
            freq[nums[right]]++;
            
            // If we have more than k distinct numbers, shrink the window
            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }
            
            // Add the number of valid subarrays ending at the current right pointer
            result += right - left + 1;
        }
        
        return result;
    }
};