class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                if (isConnected[i][j]) {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i<n; i++) {
            if (!visited[i]) {
                count++;
                dfs(mp, i, visited);
            }
        }
        return count;
    }
    void dfs(unordered_map<int, vector<int>> &mp, int u, vector<bool> &visited) {
        visited[u] = true;
        for (int &v : mp[u]) {
            if (!visited[v]) dfs(mp, v, visited);
        }
    }
};