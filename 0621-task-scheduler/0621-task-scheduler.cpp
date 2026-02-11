class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        vector<int> mp(26,0);
        for (char ch : tasks) {
            mp[ch-'A']++;
        }

        sort(mp.begin(), mp.end());
        int maxFreq = mp[25];
        int repeatedSize = maxFreq-1;
        int idleSlots = repeatedSize * n;

        for (int i = 24; i>=0; i--) {
            idleSlots -= min(mp[i], repeatedSize);
        }

        if (idleSlots > 0) {
            return tasks.size() + idleSlots;
        }

        return tasks.size();
    }
};