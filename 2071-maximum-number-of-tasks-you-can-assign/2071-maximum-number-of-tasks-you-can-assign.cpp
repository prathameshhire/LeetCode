class Solution {
public:
    bool possible(vector<int> &tasks, vector<int> &workers, int pills, int strength, int mid) {
        int pillsUsed = 0;
        multiset<int> st(workers.begin(), workers.begin() + mid);
        for (int i = mid-1; i>=0; i--) {
            int required = tasks[i];
            auto it = prev(st.end());
            if(*it >= required) st.erase(it);
            else if(pillsUsed >= pills) return false;
            else {
                auto weakest = st.lower_bound(required-strength);
                if(weakest == st.end()) {
                    return false;
                }
                st.erase(weakest);
                pillsUsed++;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size();
        int n = workers.size();
        int l = 0;
        int r = min(m, n);
        sort(tasks.begin(), tasks.end());
        sort(workers.rbegin(), workers.rend());
        int result = 0;
        while(l <= r) {
            int mid = l+(r-l)/2;
            if(possible(tasks, workers, pills, strength, mid)) {
                l = mid+1;
                result = mid;
            }
            else r = mid-1;
        }
        return result;
    }
};