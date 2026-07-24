class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        // If state is already determined: return true if safe (2), false if visiting/in a cycle (1)
        if (state[node] > 0) {
            return state[node] == 2;
        }

        // Mark as visiting (in current DFS stack)
        state[node] = 1;

        for (int neighbor : graph[node]) {
            // If any path leads to an unsafe state/cycle, this node is also unsafe
            if (!dfs(neighbor, graph, state)) {
                return false;
            }
        }

        // Mark as safe
        state[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0); // 0: unvisited, 1: visiting, 2: safe
        vector<int> safeNodes;

        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph, state)) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};