class Solution {
public:
    int t[101][101];
    int solve(int i, int j, int &m, int &n) {
        if (t[i][j] != -1) return t[i][j];
        if (i == m-1 && j == n-1) return 1;
        if ( i >= m || j >= n) return 0;
        int right = solve(i, j+1, m, n);
        int left = solve(i+1, j, m, n);
        return t[i][j] = left + right;
    }

    int uniquePaths(int m, int n) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, m, n);
    }
};