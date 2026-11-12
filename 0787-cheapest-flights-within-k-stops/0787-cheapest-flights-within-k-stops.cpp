class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) adj[f[0]].push_back({f[1], f[2]});

        // 2D distance tracking: dist[node][flights_taken]
        // Sized to k + 2 because max flights allowed = k + 1
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        dist[src][0] = 0;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();

            if (u == dst) return cost;
            if (stops > k) continue;

            // Standard Dijkstra state evaluation optimized for 2D structures
            if (cost > dist[u][stops]) continue;

            for (auto& [v, wt] : adj[u]) {
                // Moving from 'u' with 'stops' flights to 'v' means we will have 'stops + 1' flights
                if (cost + wt < dist[v][stops + 1]) {
                    dist[v][stops + 1] = cost + wt;
                    pq.push({cost + wt, v, stops + 1});
                }
            }
        }

        return -1;
    }
};