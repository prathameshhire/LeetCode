class Solution {
public:
    int N, M, K;
    int t[51][51][101];
    int solve(int index, int searchCost, int maxSoFar) {
        if (index == N) {
            if (searchCost == K) return 1;
            return 0;
        }
        if (t[index][searchCost][maxSoFar] != -1) return t[index][searchCost][maxSoFar];
        int result = 0;
        int MOD = 1e9+7;
        for (int i = 1; i<=M; i++) {
            if (i>maxSoFar) {
                result = (result + solve(index+1, searchCost+1, i)) % MOD;
            }
            else {
                result = (result + solve(index+1, searchCost, maxSoFar)) % MOD;
            }
        }
        return t[index][searchCost][maxSoFar] = result % MOD;
    }

    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(t,-1,sizeof(t));
        return solve(0,0,0);
    }
};