class Solution {
public:
    int n;

    bool check(vector<vector<int>> &distNearestThief, int safeFactor) {
        if(distNearestThief[0][0] < safeFactor) return false;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0,0});
        visited[0][0] = true;
        while(!q.empty()){
            auto temp = q.front();
            int i = temp.first;
            int j = temp.second;
            q.pop();
            if (i == n-1 && j == n-1) return true;
            for (auto &dir:directions) {
                int x = i + dir[0];
                int y = j + dir[1];
                if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y]) {
                    if (distNearestThief[x][y] < safeFactor) continue;
                    visited[x][y] = true;
                    q.push({x,y});
                }
            }
        }
        return false;
    }

    vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> distNearestThief(n, vector<int> (n, -1));
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                if (grid[i][j] == 1){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int level = 0;
        while (!q.empty()) {
            int N = q.size();
            while(N--) {
                auto temp = q.front();
                q.pop();
                int i = temp.first;
                int j = temp.second;
                distNearestThief[i][j] = level;
                for (auto &dir:directions) {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y]) {
                        visited[x][y] = true;
                        q.push({x,y});
                    }
                }
            }
            level++;
        }
        int l = 0;
        int r = level;
        int result = 0;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (check(distNearestThief, mid)) {
                result = mid;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return result;
    }
};