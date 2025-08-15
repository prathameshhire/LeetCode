class Solution {
public:
    int solve(vector<int>& nums, int i, int n, vector<int> &t) {
        if (i > n) return 0;
        if (t[i] != -1) return t[i];
        int steal = nums[i] + solve(nums, i+2, n, t);
        int skip = solve(nums, i+1, n, t);
        return t[i] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 ) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> t(n+1, -1);
        int zero = solve(nums, 0, n-2, t);
        t = vector<int> (n+1, -1);
        int one = solve(nums, 1, n-1, t);
        return max(zero, one);
    }
};