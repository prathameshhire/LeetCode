class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        vector<int> indegree(numCourses, 0);
        for (auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            indegree[a]++;
            mp[b].push_back(a);
        }
        return topo(mp, numCourses, indegree);
    }
    vector<int> topo (unordered_map<int, vector<int>> &mp, int n, vector<int> &indegree) {
        queue<int> q;
        int course = 0;
        vector<int> result;
        for (int i = 0; i<n; i++) {
            if (!indegree[i]) {
                q.push(i);
                course++;
                result.push_back(i);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &v : mp[u]) {
                indegree[v]--;
                if (!indegree[v]) {
                    result.push_back(v);
                    q.push(v);
                    course++;
                }
            }
        }
        if (course == n) return result;
        return {};
    }
};