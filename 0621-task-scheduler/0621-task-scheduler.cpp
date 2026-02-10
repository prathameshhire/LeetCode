class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        for (char c : tasks) {
            mp[c-'A']++;
        }

        priority_queue<int> maxHeap;
        for (int i = 0; i<26; i++) {
            if (mp[i] > 0) {
                maxHeap.push(mp[i]);
            }
        }

        queue<pair<int, int>> q;

        int time = 0;
        while (!maxHeap.empty() || !q.empty()) {
            time++;
            if (maxHeap.empty()) {
                time = q.front().second;
            }
            else {
                int freq = maxHeap.top()-1;
                maxHeap.pop();
                if (freq > 0) {
                    q.push({freq, time+n});
                }
            }
            if (!q.empty()) {
                if (time == q.front().second) {
                    maxHeap.push(q.front().first);
                    q.pop(); 
                }
            }
        }

        return time;

    }
};