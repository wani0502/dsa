class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
      
        vector<vector<int>> left(n + 1), right(n + 1);
       
        for (int i = 0; i < (1 << n); ++i) {
            int sum = 0, count = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    sum += nums[j];
                    count++;
                }
            }
            left[count].push_back(sum);
        }
     
        for (int i = 0; i < (1 << n); ++i) {
            int sum = 0, count = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    sum += nums[n + j];
                    count++;
                }
            }
            right[count].push_back(sum);
        }
     
        for (int i = 0; i <= n; ++i) {
            sort(right[i].begin(), right[i].end());
        }
        
        int min_diff = 2e9; 
        int target = total_sum / 2;
        
        for (int k = 0; k <= n; ++k) {
            for (int x : left[k]) {
                int required = target - x;
                
              
                auto it = lower_bound(right[n - k].begin(), right[n - k].end(), required);
                
                if (it != right[n - k].end()) {
                    int y = *it;
                    min_diff = min(min_diff, abs(total_sum - 2 * (x + y)));
                }

                if (it != right[n - k].begin()) {
                    auto it2 = it;
                    --it2;
                    int y = *it2;
                    min_diff = min(min_diff, abs(total_sum - 2 * (x + y)));
                }
            }
        }
        
        return min_diff;
    }
};