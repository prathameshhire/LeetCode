class Solution {
public:
    int m, n;
    int t[501][501];
    int minDistance(string s1, string s2) {
        m = s1.length();
        n = s2.length();
        memset(t, -1, sizeof(t));
        return solve(s1, s2, 0, 0);
    }

    int solve(string &s1, string &s2, int i, int j) {
        if(t[i][j] != -1) return t[i][j];
        
        if (i == m) return t[i][j] = n-j;
        else if (j == n) return t[i][j] = m-i;
        
        if (s1[i] == s2[j]) return t[i][j] = solve(s1, s2, i+1, j+1);
        else {
            int ins = 1 + solve(s1, s2, i, j+1);
            int del = 1 + solve(s1, s2, i+1, j);
            int replace = 1 + solve(s1, s2, i+1, j+1);

            return t[i][j] = min({ins, del, replace});
        }

        return -1;
    }
};