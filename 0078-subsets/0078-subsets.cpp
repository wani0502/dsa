class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int subsetCount = 1 << n; // This calculates 2^n
        
        // Loop through all possible combinations from 0 to (2^n - 1)
        for (int i = 0; i < subsetCount; i++) {
            vector<int> sub; // New subset for this combination
            
            // Check each bit of 'i' to see which elements to include
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    sub.push_back(nums[j]);
                }
            }
            ans.push_back(sub);
        }
        
        return ans;
    }
};