class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maximum = 0;
        for (int i = 0; i<nums.size(); i++) {
            if (i == nums.size()-1) maximum = max(abs(nums[i] - nums[0]), maximum);
            else maximum = max(abs(nums[i]-nums[i+1]), maximum);
        }
        return maximum;
    }
};