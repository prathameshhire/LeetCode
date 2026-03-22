class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &mp, int curr, int parent, vector<int> &result, vector<int> &count, string &labels) {
        char myLabel = labels[curr];
        int before = count[myLabel-'a'];
        count[myLabel-'a']++;
        for (int &v:mp[curr]) {
            if (v == parent) continue;
            DFS(mp, v, curr, result, count, labels);

        }

        int after = count[myLabel-'a'];
        result[curr] = after-before;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> mp;
        for (auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int> result(n, 0);
        vector<int> count(26, 0);

        DFS(mp, 0, -1, result, count, labels);
        return result;
    }
};