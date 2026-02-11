class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp (26,0);
        for (char ch:tasks) {
            mp[ch-'A']++;
        }
        priority_queue<int> maxHeap;
        for (auto t : mp) {
            if(t >0) maxHeap.push(t);
        }

        queue<pair<int, int>> q;
        int time = 0;
        while (!maxHeap.empty() || !q.empty()) {
            time++;
            if (maxHeap.empty()) {
                time = q.front().second;
            }

            else {
                int freq = maxHeap.top();
                maxHeap.pop();
                if (freq > 1) {
                    q.push({freq-1, time+n});
                }

            }

            if(!q.empty()) {
                if (q.front().second == time) {
                    maxHeap.push(q.front().first);
                    q.pop();
                }
            }
        }

        return time;
    }
};