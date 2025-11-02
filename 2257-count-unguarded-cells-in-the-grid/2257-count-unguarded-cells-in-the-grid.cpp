class Solution {
public:
    void markCellsAlongGuard(int row , int col , vector<vector<int>>& grid) {
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col] == 4 || grid[i][col] == 7) break;

            grid[i][col] = 1;
        }

        for (int i = row + 1; i < grid.size(); i++) {
            if (grid[i][col] == 4 || grid[i][col] == 7) break;

            grid[i][col] = 1;
        }

        for (int j = col - 1; j >= 0; j--) {
            if (grid[row][j] == 4 || grid[row][j] == 7) break;

            grid[row][j] = 1;
        }

        for (int j = col + 1; j < grid[0].size(); j++) {
            if (grid[row][j] == 4 || grid[row][j] == 7) break;

            grid[row][j] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m , vector<int>(n , 0));

        for (vector<int>& v : guards) {
            int i = v[0];
            int j = v[1];
            grid[i][j] = 7;
        }

        for (vector<int>& v : walls) {
            int i = v[0];
            int j = v[1];
            grid[i][j] = 4;
        }

        for (vector<int> guard : guards) {
            int i = guard[0];
            int j = guard[1];

            markCellsAlongGuard(i , j , grid);
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};