class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min = INT_MAX, diff = INT_MIN;
        for (int i = 0; i<nums.size(); i++) {
            if (nums[i] < min) min = nums[i];
            if (nums[i] > min) diff = max(diff, nums[i]-min);
        }
        return diff == INT_MIN ? -1 : diff;
    }
};