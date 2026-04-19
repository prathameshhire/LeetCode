class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int result = 0;
        for (int i = 0; i<nums.size(); i++) {
            if(nums[i] == 1) {
                result++;
                ans = max(ans, result);
            }else result = 0;
        }
        return ans;
    }
};