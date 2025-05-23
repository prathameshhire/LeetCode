class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> numSet;
        for (auto it:nums) {
            numSet.insert(it);
        }
        int longest = 0;
        for (auto num:numSet) {
            if (numSet.find(num-1) == numSet.end()) {
                int length = 1;
                while (numSet.find(num+length) != numSet.end()) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};