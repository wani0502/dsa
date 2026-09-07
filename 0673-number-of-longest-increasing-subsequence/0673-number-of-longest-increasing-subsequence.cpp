class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> len(n, 1); 
        
        vector<int> cnt(n, 1); 
        
        int max_len = 1;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (len[j] + 1 > len[i]) {
                       
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (len[j] + 1 == len[i]) {
                      
                        cnt[i] += cnt[j];
                    }
                }
            }
            
            max_len = max(max_len, len[i]);
        }
        
       
        int num_lis = 0;
        for (int i = 0; i < n; ++i) {
            if (len[i] == max_len) {
                num_lis += cnt[i];
            }
        }
        
        return num_lis;
    }
};