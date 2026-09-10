class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Exactly K times = (At most K times) - (At most K - 1 times)
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    
private:
    int atMost(vector<int>& nums, int k) {
        int left = 0;
        int result = 0;
        int oddCount = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            // Check if the current number is odd
            if (nums[right] % 2 != 0) {
                oddCount++;
            }
            
            // If we have more than k odd numbers, shrink the window from the left
            while (oddCount > k) {
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                left++;
            }
            
            // Add the number of valid subarrays ending at the current right pointer
            result += right - left + 1;
        }
        
        return result;
    }
};