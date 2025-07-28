class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions {{-1,0}, {1,0}, {-1,1}, {0,1}, {1,1}, {-1,-1}, {0,-1}, {1,-1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if (m == 0 || n == 0 || grid[0][0] != 0) return -1;

        auto isSafe = [&] (int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n; 
        };

        vector<vector<int>> result (m, vector<int> (n, INT_MAX));
        result[0][0] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0,0}});

        while (!pq.empty()) {
            int d = pq.top().first;
            auto node = pq.top().second;
            int x = node.first;
            int y = node.second;
            pq.pop();

            for (auto dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (isSafe(x_, y_) && !grid[x_][y_] && d+1 < result[x_][y_]) {
                    pq.push({d+1, {x_,y_}});
                    result[x_][y_] = d+1;
                }
            }
        }

        return result[m-1][n-1] == INT_MAX ? -1 : result[m-1][n-1]+1;
    }
};