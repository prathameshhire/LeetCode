class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num:nums) {
            mp[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto &p : mp) {
            pq.push({p.second, p.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            res.push_back(p.second);
        }
        return res;
    }
};