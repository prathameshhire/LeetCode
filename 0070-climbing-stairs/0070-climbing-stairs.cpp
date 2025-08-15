class Solution {
public:
    vector<int> t;
    int solve(int n) {
        if (n<0) return 0;
        if (t[n] != -1) return t[n];
        if (n==0) return 1;
        int one = solve(n-1);
        int two = solve(n-2);
        return t[n] = one + two;
    }

    int climbStairs(int n) {
        t = vector<int> (46,-1);
        return solve(n);
    }
};