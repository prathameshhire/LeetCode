class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &edge: times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int> result(n+1, INT_MAX);
        result[k] = 0;
        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto &vec : adj[node]) {
                int adjNode = vec.first;
                int d = vec.second;
                if (dist + d < result[adjNode]) {
                    result[adjNode] = dist+d;
                    pq.push({adjNode, d});
                }
            }
        }
        int ans = 0; 
        for (int i = 1; i<n+1; i++) {
            ans = max(ans, result[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};