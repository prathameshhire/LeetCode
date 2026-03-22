class Solution {
public:

    int findRight(vector<int> &nums, int target, int l, int r) {
        int right_most = -1;
        while (l<=r) {
            int mid = l + (r-l)/2;
            if (nums[mid] == target) {
                right_most = mid;
                l = mid+1;
            }
            else if(nums[mid] < target) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return right_most;
    }

    int findLeft(vector<int> &nums, int target, int l, int r) {
        int left_most = -1;
        while (l<=r) {
            int mid = l + (r-l)/2;
            if (nums[mid] == target) {
                left_most = mid;
                r = mid-1;
            }
            else if(nums[mid] < target) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return left_most;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left_most = findLeft(nums, target, 0, n-1);
        int right_most = findRight(nums, target, 0, n-1);
        return {left_most, right_most};     
    }
};