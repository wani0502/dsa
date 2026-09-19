#include <vector>

using namespace std;

class Solution {
    // Helper function to detect a cycle using DFS
    bool hasCycle(int course, vector<vector<int>>& adj, vector<int>& state) {
        // If we see a course that is currently being visited in our recursion stack, it's a cycle!
        if (state[course] == 1) return true;
        
        // If it's already fully processed and verified safe, no need to check again
        if (state[course] == 2) return false;
        
        // Mark the current course as "visiting"
        state[course] = 1;
        
        // Visit all dependent courses
        for (int nextCourse : adj[course]) {
            if (hasCycle(nextCourse, adj, state)) {
                return true;
            }
        }
        
        // Mark the course as fully "visited" (safe, no cycles downstream)
        state[course] = 2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        // Build the adjacency list
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        
        // States: 0 = Unvisited, 1 = Visiting (in current path), 2 = Visited (safe)
        vector<int> state(numCourses, 0);
        
        // Run DFS from every unvisited node
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (hasCycle(i, adj, state)) {
                    return false; // Cycle found, impossible to finish courses
                }
            }
        }
        
        return true; // No cycles found
    }
};