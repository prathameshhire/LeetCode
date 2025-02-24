class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <vector<int>> freq (nums.size()+1);
        unordered_map <int,int> mp;
        for (auto n: nums) {
            mp[n]++;
        }
        for (auto pair: mp) {
            freq[pair.second].push_back(pair.first);
        }
        vector<int> res;
        for (int i = freq.size()-1; i>0; i--) {
            for (int n:freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};