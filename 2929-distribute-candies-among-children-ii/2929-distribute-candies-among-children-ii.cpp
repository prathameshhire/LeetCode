class Solution {
public:
    long long distributeCandies(int n, int limit) {
        return dfs(0, n, limit);
    }

private:
    long long dfs(int child, int left, int limit) {
        if (left < 0)
            return 0;
        if (child == 3)  
            return left == 0;  

        long long ways = 0;
        
        for (int give = 0; give <= min(limit, left); ++give)
            ways += dfs(child + 1, left - give, limit);

        return ways;
    }
};
