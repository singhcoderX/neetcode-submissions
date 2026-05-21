class Solution {
   public:
    bool isCycle(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& current) {
        if (current[node]) {
            return true;
        }
        if (visited[node]) {
            return false;
        }
        visited[node] = true;
        current[node] = true;
        for (int i = 0; i < adj[node].size(); i++) {
            int neighbour = adj[node][i];
            if (isCycle(neighbour, adj, visited, current)) {
                return true;
            }
        }
        current[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& prerequisite : prerequisites) {
            int u = prerequisite[0];
            int v = prerequisite[1];
            adj[v].push_back(u);
        }
        vector<bool> visited(numCourses, false);  // black and white
        vector<bool> current(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && isCycle(i, adj, visited, current)) {
                return false;
            }
        }
        return true;
    }
};