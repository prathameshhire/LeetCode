class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for (int i = 0; i<n; i++) {
            if (color[i] == -1) {
                if (!bfs(graph, color, i, 0)) return false;
            }
        }
        return true;
    }

    bool bfs(vector<vector<int>>& graph, vector<int> &color, int u, int curr) {
        queue<int> q;
        color[u] = curr;
        q.push(u);
        while(!q.empty()) {
            int a = q.front();
            q.pop();
            for (int &b : graph[a]) {
                if (color[b] == color[a]) return false;
                else if (color[b] == -1) {
                    q.push(b);
                    color[b] = 1-color[a];
                }
            }
        }
        return true;
    }
};