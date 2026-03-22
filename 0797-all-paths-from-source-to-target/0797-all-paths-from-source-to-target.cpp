class Solution {
public:
    vector<vector<int>> result;
    int n;
    void dfs(unordered_map<int, vector<int>> &mp, int source, int destination, vector<int> &temp) {
        temp.push_back(source);
        if (source == destination) {
            result.push_back(temp);
        }

        for (int &v : mp[source]) {
            dfs(mp, v, destination, temp);
        }
        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> mp;
        n = graph.size();
        for (int i = 0; i<n; i++) {
            mp[i] = graph[i];
        }
        vector<int> temp;
        dfs(mp, 0, n-1, temp);
        return result;
    }
};