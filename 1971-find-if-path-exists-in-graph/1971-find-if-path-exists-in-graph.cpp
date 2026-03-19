class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> mp;
        for (auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        visited[source] = true;
        q.push(source);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == destination) return true;
            for (auto &v : mp[u]) {
                if (!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        return false;
    }
};