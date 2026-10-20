class Solution {
public:
    int maxi(vector<int>& ans) {
        int m = INT_MIN;
        for (int i = 0; i < ans.size(); i++) {
            if (m < ans[i]) m = ans[i];
        }
        return m;
    }

    bool isposs(int mid, vector<int>& bloomDay, int m, int k) {
        int bouquets = 0;
        int consecutive = 0;
        
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                consecutive++;
                if (consecutive == k) {
                    bouquets++;
                    consecutive = 0; 
                }
            } else {
                consecutive = 0; 
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
    
        if ((long long)m * k > bloomDay.size()) return -1;

        int low = 1, high = maxi(bloomDay);
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isposs(mid, bloomDay, m, k)) {
                ans = mid;  
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        return ans;
    }
};