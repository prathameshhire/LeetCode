class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> vector;
        for (int num : nums) {
            if (vector.count(num)) return true;
            vector.insert(num);
        }
        return false;
    }
};