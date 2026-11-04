class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0) {
            return -1;
        }
        
        // For a 1x1 matrix where the single cell is 0, the path length is 1
        if (n == 1 && m == 1) {
            return 1;
        }

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        // Start from (0, 0) with initial path length 1
        dist[0][0] = 1;
        q.push({1, {0, 0}});
        
        // All 8 directions (horizontal, vertical, and diagonal)
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                // Check bounds, ensure the cell is 0 (clear), and check for a shorter path
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && dis + 1 < dist[nr][nc]) {
                    dist[nr][nc] = dis + 1;
                    
                    // If we reached the bottom-right cell, return the distance
                    if (nr == n - 1 && nc == m - 1) {
                        return dis + 1;
                    }
                    
                    q.push({dis + 1, {nr, nc}});
                }
            }
        }
        
        return -1;
    }
};