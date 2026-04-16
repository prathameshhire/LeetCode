class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int result = INT_MAX;
        int val = 0;
        while(j < nums.size()) {
            val += nums[j];
            while(val >= target) {
                result = min(result, j-i+1);
                val -= nums[i];
                i++;
            }
            j++;
        }
        return result == INT_MAX ? 0 : result;
    }
};