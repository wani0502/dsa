class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // Return the max of robbing houses from 0 to n-2 OR from 1 to n-1
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }
    
private:
    // Standard House Robber I logic
    int robLinear(vector<int>& nums, int start, int end) {
        int prev1 = 0; // represents max money at i-1
        int prev2 = 0; // represents max money at i-2
        
        for (int i = start; i <= end; ++i) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};