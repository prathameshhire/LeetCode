class Solution {
public:
    int n;
    int t[301][11];
    int solve(vector<int> &jD, int index, int d) {
        if (d == 1) {
            int maxD = jD[index];
            for (int i = index; i<n; i++) {
                maxD = max(maxD, jD[i]);
            }
            return maxD;
        }

        if (t[index][d] != -1) return t[index][d];

        int finalResult = INT_MAX;
        int maxD = jD[index];

        for (int i = index; i <= n-d; i++) {
            maxD = max(maxD, jD[i]);
            int result = maxD + solve(jD, i+1, d-1);
            finalResult = min(result, finalResult);
        }
        return t[index][d] = finalResult;

    }
    int minDifficulty(vector<int>& jD, int d) {
        n = jD.size();
        memset(t, -1, sizeof(t));
        if (n < d) return -1;
        return solve(jD, 0, d);
    }
};