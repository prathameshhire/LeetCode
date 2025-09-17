class Solution {
public:
    int m, n;
    int t[501][501];
    int minDistance(string s1, string s2) {
        m = s1.length();
        n = s2.length();
        memset(t, -1, sizeof(t));
        return solve(s1, s2, m, n);
    }

    int solve(string &s1, string &s2, int m, int n) {
        if(t[m][n] != -1) return t[m][n];

        if (m == 0 || n == 0) return m+n;
        if (s1[m-1] == s2[n-1]) return t[m][n] = solve(s1, s2, m-1, n-1);
        else {
            int ins = 1 + solve(s1, s2, m, n-1);
            int del = 1 + solve(s1, s2, m-1, n);
            int replace = 1 + solve(s1, s2, m-1, n-1);

            return t[m][n] = min({ins, del, replace});
        }

        return -1;
    }
};