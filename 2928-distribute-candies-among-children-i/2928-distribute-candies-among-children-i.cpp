class Solution {
public:
    int solve(int count, int remaining, int limit) {
        if(count == 3) {
            if (remaining == 0) return 1;
            return 0;
        }

        int ways = 0;

        for (int i = 0; i <= min(remaining, limit); i++) {
            ways += solve(count+1, remaining-i, limit);
        }

        return ways;
    }

    int distributeCandies(int n, int limit) {
        return solve(0, n, limit);
    }
};