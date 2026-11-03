class Solution {
public:   
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          // Build the graph and calculate indegree of each course
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];

            adjList[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Start with courses having no prerequisites
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topoOrder;

        // Process courses using BFS (Kahn's Algorithm)
        while (!q.empty()) {
            int course = q.front();
            q.pop();

            topoOrder.push_back(course);

            // Remove this course as a prerequisite for its neighbours
            for (int nextCourse : adjList[course]) {
                indegree[nextCourse]--;

                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // If all courses are processed, a valid order exists
        if (topoOrder.size() == numCourses) {
            return topoOrder;
        }

        return {}; // Cycle exists, so no valid order
    }
};