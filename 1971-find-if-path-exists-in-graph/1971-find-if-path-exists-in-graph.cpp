class Solution {
public:
    bool dfs(int source, int destination, unordered_map<int, vector<int>> &mp, vector<bool> &visited) {
        if (source == destination) return true;
        if (visited[source]) return false;
        visited[source] = true;
        for (auto &node : mp[source]) {
            if (dfs(node, destination, mp, visited)) return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> mp;
        for (auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool> visited(n, false);
        return dfs(source, destination, mp, visited);
    }

};