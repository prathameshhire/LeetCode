class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int one = solve(0, n-2, nums);
        int two = solve(1, n-1, nums);
        return max(one, two);
    }
    int solve (int l, int r, vector<int> &nums) {
        int prev = 0, prevPrev = 0;
        for (int i = l; i <= r; i++) {
            int skip = prev;
            int take = nums[i] + prevPrev;
            int temp = max(skip, take);
            prevPrev = prev;
            prev = temp;
        }
        return prev;
    }
};