class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build the adjacency list (node -> list of {neighbor, weight})
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        
        // Step 2: Initialize distances to infinity, source distance to 0
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        
        // Min-heap priority queue storing {current_distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            // If we found a shorter path to u already, skip
            if (d > dist[u]) continue;
            
            // Relax neighboring edges
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // Step 3: Find the maximum time required to reach all nodes
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            res = max(res, dist[i]);
        }
        
        return res;
    }
};