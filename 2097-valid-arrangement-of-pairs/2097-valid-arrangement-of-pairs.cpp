class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;
        for (auto &edge : pairs) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }
        vector<int> path;
        stack<int> st;
        int start = pairs[0][0];
        for (auto &n : adj) {
            int u = n.first;
            if (outdegree[u] - indegree[u] == 1) {
                start = u;
                break;
            }
        }
        st.push(start);
        while (!st.empty()) {
            int node = st.top();
            if (!adj[node].empty()) {
                int neighbour = adj[node].back();
                adj[node].pop_back();
                st.push(neighbour);
            }
            else {
                path.push_back(node);
                st.pop();
            }
        }
        vector<vector<int>> result;
        reverse(path.begin(), path.end());
        for (int i = 0; i<path.size()-1; i++) {
            result.push_back({path[i], path[i+1]});
        }
        return result;
    }
};