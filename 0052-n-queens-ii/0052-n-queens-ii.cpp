class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> rows(n,0), upperD (2*n-1, 0), lowerD(2*n-1,0);
        rec(0, n, ans, rows, upperD, lowerD);
        return ans;
    }

    void rec(int col, int &n, int &ans, vector<int> rows, vector<int> &upperD, vector<int> &lowerD) { 
        if (col == n) {
            ans++;
            return;
        }
        for (int row = 0; row<n; row++) {
            if (!rows[row] && !upperD[n-1 + col - row] && !lowerD[row + col]) {
                rows[row]++;
                upperD[n-1+col-row]++;
                lowerD[row+col]++;
                rec(col+1, n, ans, rows, upperD, lowerD);
                rows[row]--;
                upperD[n-1+col-row]--;
                lowerD[row+col]--;
            }
        }
    }
};