class Solution {
    // Helper function to detect a cycle using DFS
    bool hasCycle(int course, vector<vector<int>>& adj, vector<int>& state) {
       if(state[course]==1) return true;
       if(state[course]==2) return false;
       state[course]=1;
       for(const auto& n : adj[course]){
            if(hasCycle(n,adj,state)) return true;
       }
       state[course]=2;
       return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(const auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int>state(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(state[i]==0){
                if(hasCycle(i,adj,state)){
                    return false;
                }
            }
        }
        return true;
    }
};
