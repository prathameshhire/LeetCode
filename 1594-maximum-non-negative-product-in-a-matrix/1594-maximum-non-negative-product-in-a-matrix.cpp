class Solution {
public:
    int m, n;
    typedef long long ll;

    int mod = 1e9+7;


    pair<ll, ll> solve(int i, int j, vector<vector<int>>& grid) {
        if (i == m-1 && j == n-1) return {grid[i][j], grid[i][j]};
    
        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if (i+1<m) {
            auto[downMax, downMin] = solve(i+1, j, grid);
            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }

        if (j+1<n) {
            auto[rightMax, rightMin] = solve(i, j+1, grid);
            maxVal = max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            minVal = min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }

        return {maxVal, minVal};

    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        auto[maxVal, minVal] = (solve(0, 0, grid));   
        return maxVal < 0 ? -1 : maxVal% mod;
    }
};