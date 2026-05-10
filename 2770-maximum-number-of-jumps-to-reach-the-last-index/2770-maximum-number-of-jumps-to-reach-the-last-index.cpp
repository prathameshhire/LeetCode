class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> t(n+1, INT_MIN);
        t[n-1] = 0;
        for(int i = n-2; i>=0; i--) {
            for(int j = i+1; j<n; j++) {
                if(abs(nums[i] - nums[j]) <= target && t[j] != INT_MIN) {
                    t[i] = max(t[i], t[j] + 1);
                }
            }
        }
        return t[0] < 0 ? -1 : t[0];
    }
};