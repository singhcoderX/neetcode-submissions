class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            pair<int, int> topEle = pq.top();
            pq.pop();
            int distanceToNode = topEle.first;
            int currentNode = topEle.second;

            for (int i = 0; i < adj[currentNode].size(); i++) {
                int neighbour = adj[currentNode][i].first;
                int distanceToNeighbour = adj[currentNode][i].second;
                if (distanceToNode + distanceToNeighbour < dist[neighbour]) {
                    dist[neighbour] = distanceToNode + distanceToNeighbour;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }

        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
