class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (auto& val : nums) {
            ans += min(val%3 + 3 % 3, abs((val%3 - 3) % 3));
        }
        return ans;
    }
};