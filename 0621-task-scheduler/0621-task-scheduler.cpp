class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        
        for (auto &t : tasks) {
            mp[t]++;
        }
        
        priority_queue<int> pq;
        
        for (auto &p : mp) {
            pq.push(p.second);
        }
        
        queue<pair<int,int>> q;
        int time = 0;
        
        while (!pq.empty() || !q.empty()) {
            time++;
            if (pq.empty()) {
                time = q.front().second;
                pq.push(q.front().first);
                q.pop();
            }else {
                int freq = pq.top();
                pq.pop();
                if (freq-1 != 0) {
                    q.push({freq-1, time+n});
                }
            }
            if (!q.empty()) {
                if (time == q.front().second) {
                    auto p = q.front();
                    q.pop();
                    pq.push(p.first);
                }
            }
        }

        return time;
    }
};