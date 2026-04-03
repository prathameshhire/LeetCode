class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long result = 0;
        for (int i = 0; i<n; i++) {
            int below = lower - nums[i];
            int index = lower_bound(nums.begin()+i+1, nums.end(), below) - nums.begin();
            int x = index-i-1;
            int above = upper - nums[i];
            index = upper_bound(nums.begin()+i+1, nums.end(), above) - nums.begin();
            int y = index-i-1;
            result += (y-x);
        }
        return result;
    }
};