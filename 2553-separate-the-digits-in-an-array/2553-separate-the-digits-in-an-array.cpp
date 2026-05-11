class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(const int num : nums) {
            string s = to_string(num);
            for(char c : s) ans.push_back(c-'0');
        }
        return ans;
    }
};