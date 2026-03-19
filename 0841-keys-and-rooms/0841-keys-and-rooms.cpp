class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i<rooms.size(); i++) {
            for (auto &key : rooms[i]) {
                mp[i].push_back(key);
            }
        }
        vector<bool> visited(rooms.size(), false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for (int &v : mp[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        for (bool b : visited) {
            if (!b) return false;
        }
        return true;
    }
};
