class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        
        // Find the longest sequential prefix sum starting at index 0
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        
        // Insert array elements into a hash set for O(1) lookup
        unordered_set<int> seen(nums.begin(), nums.end());
        
        // Find the smallest missing integer >= sum
        while (seen.count(sum)) {
            sum++;
        }
        
        return sum;
    }
};