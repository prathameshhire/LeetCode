class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long day = 0;
        unordered_map<int, long long> mp; // task and when it is next available
        int n = tasks.size();
        for (int i = 0; i<n; i++) {
            day++;
            if (mp.find(tasks[i]) == mp.end()) {
                mp[tasks[i]] = day+space+1;
            }
            else {
                day = max(day, mp[tasks[i]]);
                mp[tasks[i]] = day+space+1;
            }
        }
        return day;
    }
};