class Solution {
public:
    bool possible(vector<int> &nums, int ops, int mid) {
        for (int &num:nums) {
            ops -= (num-1)/mid;
        }
        return ops >= 0;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int result = 0;
        while (l<=r) {
            int mid = l+(r-l)/2;
            if (possible(nums, maxOperations, mid)) {
                result = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return result;
    }
};