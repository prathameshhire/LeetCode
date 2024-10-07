class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map <int,int> mp;
        for (auto it:nums) {
            mp[it]++;
        }
        int max=-1;
        for (auto it:mp) {
            if (it.second == 1) {
                if (it.first > max) {
                    max = it.first;
                }
            }
        }
        return max;
    }
};