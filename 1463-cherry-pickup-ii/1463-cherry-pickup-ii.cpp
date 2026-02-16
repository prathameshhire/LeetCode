class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int t[71][71][71] = {0};

        t[0][0][n-1] = (n==1) ? grid[0][0] : grid[0][0] + grid[0][n-1];

        for (int row = 1; row < m; row++) {
            for (int c1 = 0; c1 <= min(n-1, row); c1++) {
                for (int c2 = max(n-row-1,0); c2<n; c2++) {
                    int prevRowMax = 0;
                    for (int prevC1 = max(0, c1-1); prevC1 <= min(n-1, c1+1); prevC1++) {
                        for (int prevC2 = max(0, c2-1); prevC2 <= min(n-1, c2+1); prevC2++) {
                            prevRowMax = max(prevRowMax, t[row-1][prevC1][prevC2]);        
                        }
                    }

                    if (c1 != c2) {
                        t[row][c1][c2] = prevRowMax + grid[row][c1] + grid[row][c2];
                    }
                    else {
                        t[row][c1][c2] = prevRowMax + grid[row][c1];
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                ans = max(ans, t[m-1][i][j]);
            }
        }

        return ans;
    }
};