class Solution {
public:
    int solve(vector<int> &nums, int i, int n, vector<int> &t) {
        if (i>=n) return 0;
        if (t[i] != -1) return t[i];
        int steal = nums[i] + solve(nums, i+2, n, t);
        int skip = solve(nums, i+1, n, t);
        return t[i] = max(skip, steal);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(101, -1);
        return solve(nums, 0, n, t);
    }
};