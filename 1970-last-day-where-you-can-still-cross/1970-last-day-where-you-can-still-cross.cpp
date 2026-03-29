class Solution {
public:
    int ROW;
    int COL;

    vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0, -1}};

    bool BFS(vector<vector<int>> &grid, int r, int c) {
        queue<pair<int, int>> q;
        grid[r][c] = 1;
        q.push({r,c});

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;
            if (x == ROW-1) return true;
            for (auto &dir : directions) {
                int i = x + dir[0];
                int j = y + dir[1];
                if (i >= 0 && i < ROW && j >= 0 && j < COL && grid[i][j] == 0) {
                    grid[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
        return false;
    }

    bool check(vector<vector<int>> &cells, int mid) {
        vector<vector<int>> grid(ROW, vector<int> (COL));
        for (int i = 0; i<=mid; i++) {
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            grid[x][y] = 1;
        }

        for (int j = 0; j<COL; j++) {
            if (!grid[0][j] && BFS(grid, 0, j)) return true;
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW = row;
        COL = col;
        int l = 0;
        int r = cells.size()-1;
        int lastDay = 0;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (check(cells, mid)) {
                l = mid + 1;
                lastDay = mid;
            }
            else r = mid -1;
        }
        return lastDay + 1;
    }
};