class Solution {
public:
    bool possible(vector<int> &points, int m, long long target) {
        long long moves = 0;
        long long advancedMoves = 0;
        long long normalMoves = 0;
        for (int i = 0; i<points.size() && moves <= m; i++) {
            int gamePoint = points[i];
            long long games = (target + gamePoint - 1)/gamePoint;
            if(advancedMoves >= games) {
                advancedMoves = 0;
                normalMoves+=1;
            }
            else {
                long long pointsCovered = advancedMoves * gamePoint;
                games = (target - pointsCovered + gamePoint - 1)/gamePoint;
                moves += (2*games)-1;
                advancedMoves = max(games-1,0LL);
                moves += normalMoves;
                normalMoves = 0;
            }
        }
        return moves <= m;
    }

    long long maxScore(vector<int>& points, int m) {
        long long l = 1;
        long long r = 1e15;
        long long result = 0;
        while (l <= r) {
            long long mid = l+(r-l)/2;
            if (possible(points, m, mid)) {
                result = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return result;
    }
};