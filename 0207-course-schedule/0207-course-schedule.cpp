class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        vector<bool> visited(numCourses, 0);
        vector<bool> inRec(numCourses, 0);
        for (auto vec: prerequisites) {
            int a = vec[0];
            int b = vec[1];
            mp[b].push_back(a);
        }
        for (int i = 0; i<numCourses; i++) {
            if (!visited[i] && dfs(mp, i, visited, inRec)) {
                return false;
            }
        }
        return true;
    }
    bool dfs(unordered_map<int, vector<int>> &mp, int u, vector<bool> &visited, vector<bool> &inRec) {
        visited[u] = true;
        inRec[u] = true;

        for (int &v : mp[u]) {
            if (!visited[v] && dfs(mp, v, visited, inRec)) return true;
            if (inRec[v]) return true;
        }

        inRec[u] = false;
        return false;
    }
};