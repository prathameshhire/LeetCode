class Solution {
public:
    vector<int> t;
    int solve(vector<int> &nums, int i, int n) {
        if (i>=n) return 0;
        if (t[i] != -1) return t[i];
        int steal = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);
        return t[i] = max(skip, steal);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        t = vector<int> (101,-1);
        return solve(nums, 0, n);
    }
};