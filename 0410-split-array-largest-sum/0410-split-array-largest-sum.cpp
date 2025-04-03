class Solution {
private:
    bool canSum(int maximum, int &k, vector<int> &nums) {
        int sum = 0;
        int subarray = 1;
        for (int i = 0; i<nums.size(); i++) {
            sum+=nums[i];
            if (sum > maximum) {
                subarray++;
                sum = nums[i];
            }
        }
        return (subarray <= k);
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int res = r;
        while (l<=r) {
            int mid = l + (r-l)/2;
            if (canSum(mid,k, nums)) {
                res = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return res;
    }
};