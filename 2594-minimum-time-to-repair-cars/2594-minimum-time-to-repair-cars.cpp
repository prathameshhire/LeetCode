class Solution {
public:
    typedef long long ll;
    bool possible(vector<int> &ranks, int cars, ll time) {
        ll totalCars = 0;
        for (int i = 0; i<ranks.size(); i++) {
            totalCars += sqrt(time/ranks[i]); 
        }
        return totalCars >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        ll l = 1;
        int maxR = *max_element(ranks.begin(), ranks.end());
        ll r = 1LL * maxR * cars * cars;
        ll result = 0;
        while (l <= r) {
            ll mid = l + (r-l)/2;
            if (possible(ranks, cars, mid)) {
                result = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return result;
    }
};