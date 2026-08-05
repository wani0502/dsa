class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        vector<bool> isSuspicious(n, false);
        
        // Step 1: DFS from node k to find all suspicious methods
        auto dfs = [&](auto& self, int u) -> void {
            isSuspicious[u] = true;
            for (int v : adj[u]) {
                if (!isSuspicious[v]) {
                    self(self, v);
                }
            }
        };
        dfs(dfs, k);

        // Step 2: Check if any non-suspicious method calls a suspicious method
        for (const auto& inv : invocations) {
            int u = inv[0], v = inv[1];
            if (!isSuspicious[u] && isSuspicious[v]) {
                // Cannot remove suspicious methods; return all methods
                vector<int> all(n);
                iota(all.begin(), all.end(), 0);
                return all;
            }
        }

        // Step 3: Collect only remaining non-suspicious methods
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!isSuspicious[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};