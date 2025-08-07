class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> directions {{0,1}, {1,0}, {0,-1}, {-1,0}};
        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;
        set<pair<int, int>> visit;
        pq.push({grid[0][0], 0, 0});
        visit.insert({0,0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int t = curr[0];
            int r = curr[1];
            int c = curr[2];
            if (r == n-1 && c == n-1) return t;
            for (auto& dir : directions) {
                int row = r + dir[0];
                int col = c + dir[1];
                if (row < 0 || col < 0 || row == n || col == n || visit.count({row,col})) continue;
                visit.insert({row,col});
                pq.push({max(t, grid[row][col]), row, col});
            }
        }

        return n*n;
    }
};