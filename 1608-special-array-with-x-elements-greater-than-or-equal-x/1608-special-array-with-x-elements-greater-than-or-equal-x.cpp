class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = n;
        while (l <= r) {
            int mid = l + (r-l)/2;
            int index = lower_bound(nums.begin(), nums.end(), mid) - nums.begin();
            int count = n - index;
            if (count == mid) return mid;
            else if(count>mid) l = mid + 1;
            else r = mid-1;
        }
        return -1;
    }
};