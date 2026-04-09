class Solution {
public:
    typedef long long ll;
    bool possible(int mountainHeight, vector<int> &workerTimes, ll mid) {
        ll h = 0;
        for (int &t : workerTimes) {
            h += (ll) (sqrt(2.0*mid/t + 0.25)-0.5);
            if (h >= mountainHeight) return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll l = 1;
        ll tmax = *max_element(workerTimes.begin(), workerTimes.end());
        ll r = (tmax * mountainHeight * (mountainHeight+1))/2;
        ll result = 0;
        while(l <= r) {
            ll mid = l+(r-l)/2;
            if (possible(mountainHeight, workerTimes, mid)) {
                r = mid-1;
                result = mid;
            }
            else l = mid+1;
        }
        return result;
    }
};