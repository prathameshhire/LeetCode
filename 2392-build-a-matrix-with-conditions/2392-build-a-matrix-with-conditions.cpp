class Solution {
public:
    vector<int> top(vector<vector<int>>& edges, int n) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n+1,0);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        int count = 0;
        for (int i = 1; i<=n; i++) {
            if (!indegree[i]) {
                q.push(i);
                count++;
            }
        }
        vector<int> topoOrder;
        while (!q.empty()) {
            int u =q.front();
            q.pop();
            topoOrder.push_back(u);

            for (int &v: adj[u]) {
                indegree[v]--;
                if (!indegree[v]) {
                    q.push(v);
                    count++;
                }
            }
        }
        if (count!=n) {
            return {};
        }
        return topoOrder;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> row = top(rowConditions, k);
        vector<int> col = top(colConditions, k);
        if (row.empty() || col.empty()) {
            return {};
        }
        vector<vector<int>> matrix(k, vector<int>(k,0));
        for (int i = 0; i<k; i++) {
            for (int j = 0; j<k; j++){
                if (row[i] == col[j]) {
                    matrix[i][j] = row[i];
                }
            }
        }
        return matrix;
    }
};