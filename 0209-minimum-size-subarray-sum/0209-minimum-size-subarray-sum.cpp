class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, total = 0;
        int res = nums.size()+1;
        for (int r = 0; r<nums.size(); r++) {
            total += nums[r];
            while (total >= target) {
                res = min(res, r-l+1);
                total-=nums[l++];
            }
        }
        if (res == nums.size()+1) return 0;
        return res;
    }
};