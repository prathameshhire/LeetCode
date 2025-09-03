class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> prevIdx(n, -1);
        int maxL = 1;
        int lastChosenIndex = 0;
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j]+1) {
                        dp[i] = dp[j] + 1;
                        prevIdx[i] = j;
                        if (maxL < dp[i]) {
                            maxL = dp[i];
                            lastChosenIndex = i;
                        }
                    }
                }
            }
        }
        vector<int> result;
        while (lastChosenIndex != -1) {
            result.push_back(nums[lastChosenIndex]);
            lastChosenIndex = prevIdx[lastChosenIndex];
        }
        return result;
    }
};