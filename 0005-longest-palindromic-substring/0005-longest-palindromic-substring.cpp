class Solution {
public:
    int t[1001][1001];
    bool solve(int i, int j, string &s) {
        if (t[i][j] != -1) return t[i][j];
        if (i >= j) return t[i][j] = 1;
        if (s[i] == s[j]) return t[i][j] = solve (i+1, j-1, s);
        return t[i][j] = 0;
    }
    string longestPalindrome(string s) {
        memset(t, -1, sizeof(t));
        int n = s.length();
        int maxLen = 0;
        int sp = 0;
        for (int i = 0; i<n; i++) {
            for (int j = i; j<n; j++) {
                if (solve(i, j, s)) {
                    if (j-i+1 > maxLen) {
                        sp = i;
                        maxLen = j-i+1;
                    }
                }
            }
        }

        return s.substr(sp, maxLen);
    }
};