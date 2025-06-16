class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min = INT_MAX;
        int diff = INT_MIN;
        int index = -1;
        for (int i = 0; i<nums.size(); i++) {
            if (nums[i] < min) {
                min = nums[i];
                index = i;
            }
            if (nums[i] > min) diff = max(diff, nums[i]-min);
        }
        return diff == INT_MIN ? -1 : diff;
    }
};