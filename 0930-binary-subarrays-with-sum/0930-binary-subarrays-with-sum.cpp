class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i = 0, j = 0;
        int n = nums.size();
        int sum = 0;
        int result = 0;
        int zeros = 0;
        while(j < n) {
            sum += nums[j];
            while(i < j && (nums[i] == 0 || sum > goal)) {
                if(nums[i] == 0) zeros++;
                else zeros = 0;
                sum -= nums[i];
                i++;
            }
            if(sum == goal) result += 1 + zeros;
            j++;
        }
        return result;
    }
};