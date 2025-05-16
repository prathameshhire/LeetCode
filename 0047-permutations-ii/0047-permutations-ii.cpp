class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        unordered_map <int, int> mp;
        for (int n:nums) mp[n]++;
        rec(nums, res, subset, mp);
        return res;
    }
    void rec(const vector<int> &nums, vector<vector<int>> &res, vector<int> &subset, unordered_map<int, int> &mp) {
        if (subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }
        for (auto s: mp)  {// try pair <int,int> s;
            if (s.second > 0) {
                subset.push_back(s.first);
                mp[s.first] -= 1;
                rec(nums, res, subset, mp);
                mp[s.first] += 1;
                subset.pop_back();
            }
        }
    }
};