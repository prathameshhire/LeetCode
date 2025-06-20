class Solution {
public:
    bool isValid(vector<int> &nums, int mid, int n) {
        vector<long long> arr(nums.begin(), nums.end());
        long long buffer = 0;
        for (int i = 0; i<n-1; i++) {
            if (arr[i] > mid) return false;
            buffer = mid - arr[i];
            arr[i+1] -= buffer;
        }
        return arr[n-1] <= mid;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int result = 0;
        int left = 0;
        int right = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        while (left<=right) {
            int mid = left + (right-left)/2;
            if (isValid(nums, mid, n)) {
                result = mid;
                right = mid-1;
            }
            else left = mid+1;
        } 
        return result;
    }
};