class Solution {
public:
    bool bfs(int u, vector<int> &visited, unordered_map<int, vector<int>> &mp) {
        queue<int> q;
        q.push(u);
        visited[u] = 1;
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            for (int &v: mp[temp]) {
                if (visited[temp] == visited[v]) return false;
                if (visited[v] == -1) {
                    q.push(v);
                    visited[v] = 1 - visited[temp];
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i<dislikes.size(); i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int> visited(n+1, -1);
        for (int i = 1; i<=n; i++) {
            if (visited[i] == -1) {
                if (!bfs(i, visited, mp)) return false;
            }
        }

        return true;
    }
};