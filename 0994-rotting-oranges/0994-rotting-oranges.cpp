class Solution {
public:
    vector<vector<int>> directions {{0,1}, {1,0},{-1,0}, {0,-1}};
    typedef pair<int, int> P;
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        auto isSafe = [&] (int x, int y) {
            return x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1;
        };

        queue<P> q;
        int freshCount = 0;
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                } 
                else if(grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if (!freshCount) {
            return 0;
        }

        int minutes = -1;
        while (!q.empty()) {
            int n = q.size();
            while(n--) {
                P curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;

                for (auto &dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if (isSafe(new_i, new_j)) {
                        grid[new_i][new_j] = 2;
                        q.push({new_i, new_j});
                        freshCount--;
                    }
                }
            }

            minutes++;
        }

        return freshCount == 0 ? minutes : -1;
    }
};