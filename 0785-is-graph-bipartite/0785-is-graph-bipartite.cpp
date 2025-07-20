class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i<n; i++) {
            mp[i] = graph[i];
        }
        vector<int> color(n,-1);
        for (int i = 0; i<n; i++) {
            if (color[i] == -1) {
                if (!dfs(mp, color, i, 0)) return false;
            }
        }
        return true;
    }
    bool dfs(unordered_map<int, vector<int>> &mp, vector<int> &color, int u, int currColor) {
        color[u] = currColor;
        int colorV;
        for (int &v : mp[u]) {
            if (color[v] == color[u]) return false;
            if (color[v] == -1) colorV = 1-color[u];
            if (color[v] == -1 && !dfs(mp, color, v, colorV)) return false;
        }
        return true;
    }
};