class Solution {
public:
    long long findTrips(long long mid, vector<int> &time) {
        long long ans = 0;
        for (auto &t : time) {
            ans += mid/t;
        }
        return ans;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int minTime = INT_MAX;
        for (int t : time) {
            minTime = min(minTime, t);
        }
        long long r = static_cast<long> (minTime) * totalTrips;
        long long l = 1;
        long long bestTime = r;
        while (l<r) {
            long long mid = l + (r-l)/2;
            long long currTrips = findTrips(mid, time);
            if (currTrips < totalTrips) {
                l = mid+1;
            }
            else {
                r = mid;
                bestTime = r;
            }
        }
        return bestTime;
    }
};