class Solution {
public:
    int n;
    int t[1001];
    int solve(vector<int> &arr, int i, int d) {
        int result = 1;
        if(t[i] != -1) return t[i];
        for(int j = i-1; j >= max(i-d, 0); j--) {
            if(arr[j] >= arr[i]) break;
            result = max(result, 1+solve(arr, j, d));
        }
        for(int j = i+1; j <= min(i+d, n-1); j++) {
            if(arr[j] >= arr[i]) break;
            result = max(result, 1+solve(arr, j, d));
        }
        return t[i] = result;
    }

    int maxJumps(vector<int>& arr, int d) {
        memset(t, -1, sizeof(t));
        int result = 1;
        n = arr.size();
        for(int i = 0; i<n; i++) {
            result = max(result, solve(arr, i, d));
        }
        return result;
    }
};