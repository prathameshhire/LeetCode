class Solution {
public:
    pair<int, int> BFS(unordered_map<int, vector<int>> &adj, int source) {
        queue<int> q;
        q.push(source);
        unordered_map<int, bool> visited;
        visited[source] = true;
        int distance = 0;
        int farthestNode = source;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();
                farthestNode = curr;
                for (auto &nbr : adj[curr]) {
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
            if (!q.empty()) {
                distance++;
            }
        }
        return {farthestNode, distance};
    }

    int findDia(unordered_map<int, vector<int>> &adj) {
        auto[farthestNode, dist] = BFS(adj, 0);
        auto[otherEnd, diameter] = BFS(adj, farthestNode);
        return diameter;
    }

    unordered_map<int, vector<int>> buildAdj(vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }


    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = buildAdj(edges1);
        unordered_map<int, vector<int>> adj2 = buildAdj(edges2);

        int d1 = findDia(adj1);
        int d2 = findDia(adj2);
        int combined = (d1+1)/2 + (d2+1)/2 + 1;
        return max({d1,d2,combined});
    }
};