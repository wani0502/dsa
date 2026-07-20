class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        // Create a result grid of the same dimensions
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                // 1. Convert 2D (r, c) to 1D index
                int old_index = r * n + c;
                
                // 2. Calculate new 1D index after k shifts
                int new_index = (old_index + k) % total;
                
                // 3. Convert new 1D index back to 2D (new_r, new_c)
                int new_r = new_index / n;
                int new_c = new_index % n;
                
                // 4. Place value in result
                result[new_r][new_c] = grid[r][c];
            }
        }
        
        return result;
    }
};