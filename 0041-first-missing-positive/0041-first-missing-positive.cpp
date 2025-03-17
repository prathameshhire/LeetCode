class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i<nums.size(); i++) {
            if (nums[i]<0) nums[i] = 0;
        }

        for (int i = 0; i<nums.size(); i++) {
            int absol = abs(nums[i]);
            if (absol>=1 && absol<=nums.size()) {
                if (nums[absol-1] > 0) nums[absol-1] *= -1;
                else if (nums[absol-1] == 0) nums[absol-1] = -1*(nums.size()+1);
            }
        }

        for (int i = 1; i<=nums.size(); i++) {
            if (nums[i-1]>=0) return i; 
        }
        return nums.size()+1;
    }
};