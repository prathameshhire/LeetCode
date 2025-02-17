class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i=0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (int j=0; j<nums.size(); j++) {
            if (mp[nums[j]] > 1) {
                return true;
            }
        }
        return false;
    }
};