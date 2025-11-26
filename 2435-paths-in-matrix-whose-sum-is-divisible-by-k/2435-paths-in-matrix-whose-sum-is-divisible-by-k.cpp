const int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int K) {
          int R = grid.size(), C = grid[0].size();
        vector<vector<vector<int>>> dp(R + 1, vector<vector<int>>(C + 1, vector<int>(K, 0)));
        vector<vector<vector<bool>>> done(R + 1, vector<vector<bool>>(C + 1, vector<bool>(K, 0)));
        function<int(int, int, int)> rec = [&](int r, int c, int mod_sum) {
            if (r == R || c == C) return 0;
            int new_mod_sum = (mod_sum + grid[r][c]) % K;
            if (r == R - 1 && c == C - 1) return (new_mod_sum ? 0 : 1);
            int &ans = dp[r][c][mod_sum];
            if (!done[r][c][mod_sum]) {
                ans = (rec(r + 1, c, new_mod_sum) + rec(r, c + 1, new_mod_sum)) % MOD;
                done[r][c][mod_sum] = 1;
            }
            return ans;
        };
        return rec(0, 0, 0);
    }
};