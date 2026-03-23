class Solution {
public:
    int findPivot(vector<int> &nums, int l, int r) {
        int mid;
        while(l<r) {
            mid = l + (r-l)/2;
            if (nums[mid] > nums[r]) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        mid = l + (r-l)/2;
        return mid;
    }

    int binarySearch(vector<int> &nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (nums[mid] > target) {
                r = mid-1;
            }
            else if(nums[mid] < target) {
                l = mid+1;
            }
            else if (target == nums[mid]) return mid;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot_index = findPivot(nums, 0, n-1);
        int idx = binarySearch(nums, 0, pivot_index-1, target);
        if (idx != -1) return idx;
        idx = binarySearch(nums, pivot_index, n-1, target);
        return idx;
    }
};