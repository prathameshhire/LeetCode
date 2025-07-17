class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                if (isConnected[i][j] == 1) {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, 0);
        int count = 0;

        for (int i = 0; i<n; i++) {
            if (!visited[i]) {
                bfs (mp, i, visited);
                count++;
            }
        }

        return count;
    }

    void bfs (unordered_map<int, vector<int>> &mp, int u, vector<bool> &visited) {
        queue<int> q;
        q.push(u);
        visited[u] = 1;

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v:mp[u]) {
                if (!visited[v]) {
                    bfs(mp, v, visited);
                }
            }
        }

    }
};