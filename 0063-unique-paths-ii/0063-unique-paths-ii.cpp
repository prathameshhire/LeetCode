class Solution {
public:
    int t[101][101];
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if (t[i][j] != -1) return t[i][j];
        if (i >= m || j >= n || grid[i][j] == 1) return 0;
        if (i == m-1 && j == n-1) return 1;
        int right = solve(i, j+1, m, n, grid);
        int down = solve(i+1, j, m, n, grid);
        return t[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(t, -1, sizeof(t));
        return solve(0,0, m, n, grid);
    }
};