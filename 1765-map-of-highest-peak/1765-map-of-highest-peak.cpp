class Solution {
public:
    vector<vector<int>> directions {{0,1}, {0,-1}, {1,0}, {-1,0}};
    typedef pair<int, int> P;
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n,-1));
        queue<P> q;
        
        auto isSafe = [&] (int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n && height[x][y] == -1;
        };

        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                if (isWater[i][j]) {
                    height[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                auto curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;

                for (auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if (isSafe(i_, j_)) {
                        height[i_][j_] = height[i][j] + 1;
                        q.push({i_, j_});
                    }

                }
            }
        }
        return height;
    }
};