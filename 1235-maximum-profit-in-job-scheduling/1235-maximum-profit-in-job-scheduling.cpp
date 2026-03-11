class Solution {
public:
    int n;
    int t[50001];
    // {1, 3, 50}, {2, 4, 10}, {3, 5, 40}, {3, 6, 70}

    int search(vector<vector<int>> &arr, int l, int target) {
        int r = n-1;
        int result = n+1;

        while (l <= r) {
            int mid = l+(r-l)/2;
            if (arr[mid][0] >= target) {
                result = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }

        return result;
    }

    int solve(vector<vector<int>> &arr, int index) {
        if (index >= n) return 0;
        if (t[index] != -1) return t[index];
        int next = search(arr, index+1, arr[index][1]);

        int taken = arr[index][2] + solve(arr, next);
        int notTaken = solve(arr, index+1);

        return t[index] = max(taken, notTaken);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(t, -1, sizeof(t));
        n = startTime.size();
        vector<vector<int>> arr(n, vector<int> (3,0));
        
        for (int i = 0; i<n; i++) {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        sort(arr.begin(), arr.end());

        return solve(arr, 0);
    }
};