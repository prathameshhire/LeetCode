class Solution {
public:
    bool valid(vector<int> &nums, int mid, int p) {
        int correct = 0;
        for(int i = 0; i<nums.size()-1;i++) {
            if (nums[i+1] - nums[i] <= mid) {
                correct++;
                i++;
            } else continue;
        }
        return correct >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums[n-1] - nums[0];
        int result = INT_MAX;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (valid(nums, mid, p)) {
                result = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return result;
    }
};