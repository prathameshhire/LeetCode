class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        for (auto pre:prerequisites) {
            mp[pre[1]].push_back(pre[0]);
        }
        vector<bool> visited (numCourses, false);
        vector<bool> inRec (numCourses, false);
        for (int i = 0; i<numCourses; i++) {
            if (!visited[i] && !DFS(mp, i, visited, inRec)) {
                return false;
            }
        }
        return true;
    }
    bool DFS(unordered_map<int, vector<int>> &mp, int u, vector<bool> &visited, vector<bool> &inRec) {
        visited[u] = true;
        inRec[u] = true;
        for (int v:mp[u]) {
            if (visited[v] == false && !DFS(mp, v, visited, inRec)) return false;
            else if(inRec[v] == true) return false; 
        }
        inRec[u] = false;
        return true;
    }
};