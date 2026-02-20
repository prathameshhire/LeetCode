class Solution {
public:
    int lastPoint;
    map<pair<int, int>, int> mp;
    int solve(int i, int maxEnd, vector<pair<int, int>> &range) {
        if (i == range.size()) {
            if (maxEnd >= lastPoint) return 0;
            else return 1e9;
        }

        if (maxEnd < range[i].first) return mp[{i, maxEnd}] = 1e9;
        
        if (mp.find({i, maxEnd}) != mp.end()) return mp[{i, maxEnd}];
        
        int tapOpen = 1 + solve(i+1, max(maxEnd, range[i].second), range);
        int tapClosed = solve(i+1, maxEnd, range);
        
        return mp[{i, maxEnd}] = min(tapOpen, tapClosed);
    }

    int minTaps(int n, vector<int>& ranges) {
        lastPoint = n;
        vector<pair<int, int>> range;
        for (int i = 0; i<ranges.size(); i++) {
            int left = max(0, i-ranges[i]);
            int right = min(n, i+ranges[i]);
            range.push_back({left, right});
        }
        sort(range.begin(), range.end());
        int result = solve(0,0,range);
        return result == 1e9 ? -1 : result;
    }
}; 