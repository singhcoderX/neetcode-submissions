class DSU {
   public:
    vector<int> size;
    vector<int> parent;

    DSU(int n) {
        size = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int find(int vertex) {
        if (parent[vertex] == vertex) {
            return vertex;
        } else {
            parent[vertex] = find(parent[vertex]);
            return parent[vertex];
        }
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            if (size[rootA] < size[rootB]) {
                parent[rootA] = rootB;
                size[rootB] += size[rootA];
            } else {
                parent[rootB] = rootA;
                size[rootA] += size[rootB];
            }
            return true;
        } else {
            return false;
        }
    }
};

class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        for (auto& edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            if (!dsu.unite(u, v)) {
                return {u + 1, v + 1};
            }
        }

        return {};
    }
};
