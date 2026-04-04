class Solution {
public:
    bool possible(vector<int>&nums, int k, int mid) {
        for (int i = 0; i<nums.size(); i++) {
            if (nums[i] <= mid) {
                i++;
                k--;
            }
        }
        return k <= 0;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = 0;
        int r = *max_element(nums.begin(), nums.end());
        int result = 0;
        while (l<=r) {
            int mid = l+(r-l)/2;
            if (possible(nums, k, mid)) {
                result = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return result;
    }
};