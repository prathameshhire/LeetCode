class Solution {
public:
    int t[201][201];
    int solve(int i, int j, vector<vector<int>>& grid) {
        if (t[i][j] != -1) return t[i][j];
        if (i == grid.size()-1 && j == grid[0].size()-1) return t[i][j] = grid[i][j];
        if (i == grid.size()-1) return t[i][j] = grid[i][j] + solve(i, j+1, grid);
        else if (j == grid[0].size()-1) return t[i][j] = grid[i][j] + solve(i+1, j, grid);
        else return t[i][j] = grid[i][j] + min(solve(i+1, j, grid), solve(i, j+1, grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, grid);
    }
};