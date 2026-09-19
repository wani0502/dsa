#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Queue to store the coordinates of our cells
        queue<pair<int, int>> q;
        // Result matrix initialized with -1 to indicate unvisited cells
        vector<vector<int>> dist(m, vector<int>(n, -1));
        
        // Step 1: Find all 0s and push them into the queue as our starting points
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0; // Distance to itself is 0
                }
            }
        }
        
        // Array to help traverse up, down, left, right easily
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Step 2: Multi-source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            // Check all 4 adjacent neighbors
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                // If the neighbor is within bounds and hasn't been visited yet (-1)
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    // Its distance is simply the current cell's distance + 1
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc}); // Add neighbor to queue to process its neighbors later
                }
            }
        }
        
        return dist;
    }
};