class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 = uncolored, 0 and 1 = colors

        // Loop over all nodes to handle disconnected components
        for (int i = 0; i < n; ++i) {
            if (color[i] != -1) continue; // Skip if already colored

            queue<int> q;
            q.push(i);
            color[i] = 0; // Assign first color

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    // If neighbor is not colored, give it the opposite color
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } 
                    // If neighbor has the same color, the graph is not bipartite
                    else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};