class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        int ans = 0;
        int flag = 1;
        while (j<nums.size()) {
            if(nums[j] == 0) {
                if(flag == 0) {
                    while(nums[i] != 0) {
                        i++;
                    }
                    i++;
                } else flag--;
            }
            ans = max(ans, j-i);
            j++;
        }
        return ans;
    }
};