class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int cost = flight[2];
            adj[u].push_back({v,cost});
        }

        vector<int> cost(n, INT_MAX);
        queue<pair<int, int>> q;
        cost[src] = 0;
        q.push({src,0});
        int steps = 0;
        
        while (!q.empty() && steps <= k) {
            int n = q.size();
            while (n--) {
                auto [node, cst] = q.front();
                q.pop();
                for(auto [v, dist] : adj[node]) {
                    if (cost[v] > cst + dist) {
                        cost[v] = cst+dist;
                        q.push({v, cst+dist});
                    }
                }
            }
            steps++;
        }

        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};