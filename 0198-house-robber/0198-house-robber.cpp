class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        int prevPrev = 0;
        int prev = nums[0];
        for (int i = 1; i<n; i++) {
            int steal = nums[i] + prevPrev;
            int skip = prev;
            int temp = max(steal, skip);
            prevPrev = prev;
            prev = temp;
        }
        return prev;
    }
};