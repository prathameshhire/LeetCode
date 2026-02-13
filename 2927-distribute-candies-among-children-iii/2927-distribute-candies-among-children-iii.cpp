class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;
        int maxCh1 = min(limit, n);
        int minCh1 = max(0, n-2*limit);

        for (int i = minCh1; i <= maxCh1; i++) {
            int N = n-i;
            int maxCh2 = min(limit, N);
            int minCh2 = max(0, N-limit);

            ways += maxCh2 - minCh2 +1;
        }

        return ways;
    }
};