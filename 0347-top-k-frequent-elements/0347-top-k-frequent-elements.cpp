class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        vector<vector<int>> arr(nums.size()+1);
        for (auto &p:mp) {
            arr[p.second].push_back(p.first);
        }
        vector<int> result;
        for (int i = arr.size()-1; i>0; i--) {
            for (int j : arr[i]) {
                result.push_back(j);
                if(result.size() == k) return result;
            }
        }
        return result;
    }
};