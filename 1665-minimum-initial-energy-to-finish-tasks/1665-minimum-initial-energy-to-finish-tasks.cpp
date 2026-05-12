class Solution {
public:
    typedef long long ll;

    bool isPossible(vector<vector<int>> &tasks, ll mid) {
        for(int i = 0; i<tasks.size(); i++) {
            if(tasks[i][1] > mid) return false;
            mid -= tasks[i][0];
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b){
            int diff1 = a[1]-a[0];
            int diff2 = b[1]-b[0];
            return diff1 > diff2;
        });
        ll l = 0;
        ll r = 1e9;
        ll ans = 1e9;
        while(l <= r) {
            ll mid = l+(r-l)/2;
            if(isPossible(tasks, mid)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};