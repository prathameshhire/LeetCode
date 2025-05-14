class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(0,nums,0);
    }
    int dfs (int i, vector<int> &nums, int total) {
        if (i == nums.size()) return total;
        return dfs(i+1, nums, total ^ nums[i]) + dfs(i+1, nums, total);
    }
};