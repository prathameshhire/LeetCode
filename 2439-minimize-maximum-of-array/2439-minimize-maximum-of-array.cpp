class Solution {
public:
    bool valid(vector<int> &nums, int mid) {
        vector<long long> arr(nums.begin(), nums.end());
        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            if (arr[i] > mid) return false;
            long long diff = static_cast <long long> (mid) - arr[i];
            arr[i+1] -= diff;
        }
        return arr[n-1] <= mid;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int l = 0;
        int r = *max_element(nums.begin(), nums.end());
        int result;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (valid(nums, mid)){
                result = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return result;
    }
};