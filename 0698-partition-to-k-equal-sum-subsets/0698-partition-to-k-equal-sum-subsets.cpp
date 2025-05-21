class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%k != 0) return false;
        sort(nums.rbegin(), nums.rend());
        int target = sum/k;
        vector<int> used (nums.size(),0);
        return rec(nums, used, target, 0, k, 0);
    }
    bool rec(const vector<int> &nums, vector<int> &used, const int &target, int index, int k, int subsetSum) {
        if (k == 0) return true;
        if (subsetSum == target) return rec(nums, used, target, 0, k-1, 0);
        for (int i = 0; i<nums.size(); i++) {
            if (used[i] || subsetSum + nums[i] > target) continue;
            used[i] = 1;
            if (rec(nums, used, target, i+1, k, subsetSum + nums[i])) return true;
            used[i] = 0;
        }
        return false;
    }
};