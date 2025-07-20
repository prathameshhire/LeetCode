class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for (int i = 0; i<n; i++) {
            if (color[i] == -1) {
                if (!dfs(graph, color, i, 0)) return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph, vector<int> &color, int u, int currColor) {
        color[u] = currColor;
        int colorV;
        for (int &v : graph[u]) {
            if (color[v] == color[u]) return false;
            if (color[v] == -1) colorV = 1-color[u];
            if (color[v] == -1 && !dfs(graph, color, v, colorV)) return false;
        }
        return true;
    }
};