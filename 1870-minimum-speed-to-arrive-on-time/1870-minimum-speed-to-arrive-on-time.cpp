class Solution {
public:
    double possible (vector<int> &dist, int speed) {
        int n = dist.size();
        double time = 0.0;
        for (int i = 0; i<n-1; i++) {
            time += ceil(double(dist[i]) / double(speed));
        }
        time += double(dist[n-1]/double(speed));
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 0;
        int r = 1e7;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (possible(dist, mid) <= hour) {
                ans = mid;
                r = mid-1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};