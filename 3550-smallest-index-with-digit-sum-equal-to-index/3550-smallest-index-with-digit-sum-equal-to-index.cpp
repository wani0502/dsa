class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            int digitSum = 0;
            
            // Calculate the sum of the digits of nums[i]
            while (val > 0) {
                digitSum += val % 10;
                val /= 10;
            }
            
            // Return the index immediately if the condition is met
            if (digitSum == i) {
                return i;
            }
        }
        
        // Return -1 if no such index exists
        return -1;
    }
};