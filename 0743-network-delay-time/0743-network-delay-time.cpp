class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i<times.size(); i++) {
            mp[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(n+1,INT_MAX);
        result[k] = 0;
        pq.push({0,k});
        while(!pq.empty()) {
            auto start = pq.top();
            int d = start.first;
            int node = start.second;
            pq.pop();
            for (auto &neighbour : mp[node]) {
                int side = neighbour.first;
                int dist = neighbour.second;
                if (dist+d < result[side]) {
                    result[side] = dist+d;
                    pq.push({dist+d, side});
                }
            }
        }
        int ans = *max_element(result.begin()+1, result.end());
        return ans == INT_MAX ? -1 : ans;    
    }
};