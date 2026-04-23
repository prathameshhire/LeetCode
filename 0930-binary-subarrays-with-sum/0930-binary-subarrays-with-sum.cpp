class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int result = 0;
        int cumSum = 0;
        mp[0]++;
        for(int i = 0; i<n; i++) {
            cumSum += nums[i];
            if(mp.find((cumSum - goal)) != mp.end()) {
                result += mp[cumSum - goal];
            }
            mp[cumSum]++;
        }
        return result;
    }
};