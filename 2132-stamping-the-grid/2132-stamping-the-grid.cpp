class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size();
        int n = grid[0].size();
        int h = stampHeight;
        int w = stampWidth;


        int p[m][n];

        memset(p, 0, sizeof(p));
    
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                p[i][j] = grid[i][j];
                if (i-1 >= 0) p[i][j] += p[i-1][j];
                if (j-1 >= 0) p[i][j] += p[i][j-1];
                if (i-1 >= 0 && j-1 >= 0) p[i][j] -= p[i-1][j-1];
            }
        }

        int stamp[m][n];

        memset(stamp, 0, sizeof(stamp));

        for (int i = 0; i<=m-h; i++) {
            for (int j = 0; j<=n-w; j++) {
                int count = p[i+h-1][j+w-1];
                if (i-1 >= 0) count -= p[i-1][j+w-1];
                if (j-1 >= 0) count -= p[i+h-1][j-1];
                if (i-1 >= 0 && j-1 >= 0) count += p[i-1][j-1];

                if (count == 0) stamp[i][j] = 1;
            }
        }

        memset(p, 0, sizeof(p));

        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                p[i][j] = stamp[i][j];
                if (i-1 >= 0) p[i][j] += p[i-1][j];
                if (j-1 >= 0) p[i][j] += p[i][j-1];
                if (i-1 >= 0 && j-1 >= 0) p[i][j] -= p[i-1][j-1];
            }
        }


        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                if (grid[i][j] == 1) continue;

                int cnt = p[i][j];
                if (i-h >= 0) cnt -= p[i-h][j];
                if (j-w >= 0) cnt -= p[i][j-w];
                if (i-h >= 0 && j-w >= 0) cnt += p[i-h][j-w];
                
                if (cnt == 0) return false;
            }
        }

        return true;
    }
};