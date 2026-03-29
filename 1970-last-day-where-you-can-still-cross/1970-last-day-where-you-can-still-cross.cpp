class Solution {
public:
    int ROW;
    int COL;

    vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0, -1}};

    bool DFS(vector<vector<int>> &grid, int r, int c) {
        if (r < 0 || r >= ROW || c < 0 || c >= COL || grid[r][c]) return false;
        if (r == ROW-1) return true;
        grid[r][c] = 1;
        for (auto &dir : directions) {
            int i = r + dir[0];
            int j = c + dir[1];
            if (DFS(grid, i, j)) {
                return true;
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
            if (DFS(grid, 0, j)) return true;
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