class Solution {
public:
    typedef long long ll;
    bool check(vector<int>& batteries, ll mid, int n) {
        ll time = n * mid;
        for (auto &battery : batteries) {
            time -= min((ll)battery, mid);
            if (time <= 0) return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l = *min_element(batteries.begin(), batteries.end());
        ll time = 0;
        for (int battery: batteries) {
            time += battery;
        }
        ll r = time/n;
        ll ans = 0;
        while (l <= r) {
            ll mid = l + (r-l)/2;
            if (check(batteries, mid, n)) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};