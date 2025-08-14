class Solution {
public:
    void dfs(int u, vector<int>& visited, unordered_map<int, vector<int>> &adj, stack<int>& st, bool& cycle) {
        visited[u] = 1;
        for (int& v : adj[u]) {
            if (visited[v] == 0) {
                dfs(v, visited, adj, st, cycle);
            }
            else if(visited[v] == 1) {
                cycle = true;
                return;
            }
        }

        visited[u] = 2;
        st.push(u);
    }
    vector<int> top(vector<vector<int>>& edges, int n) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<int> visited(n+1, 0);
        stack<int> st;
        vector<int> order;
        bool cycle = false; 
        for (int i = 1; i<=n; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, st, cycle);
                if (cycle) return {};
            }
        }

        while(!st.empty()) {
            order.push_back(st.top());
            st.pop();
        }

        return order;
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