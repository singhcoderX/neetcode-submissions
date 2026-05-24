class Solution {
   public:
    bool dfs(int n, vector<vector<int>>& adj, vector<bool>& visited, int src, int parent) {
        for (auto& neighbour : adj[src]) {
            if (neighbour != parent && visited[neighbour]) {
                // cycle is there
                return true;
            }
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                if (dfs(n, adj, visited, neighbour, src)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        visited[0] = true;
        if (dfs(n, adj, visited, 0, -1)) {
            return false;
        }

        for (auto v : visited) {
            if (!v) {
                return false;
            }
        }

        return true;
    }
};
