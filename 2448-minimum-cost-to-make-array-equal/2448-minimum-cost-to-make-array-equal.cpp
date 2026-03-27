class Solution {
public:
    typedef long long ll;

    ll check(vector<int> &nums, vector<int> &cost, ll mid) {
        ll ans = 0;
        for (int i = 0; i<nums.size(); i++) {
            ans += static_cast<long long> (abs(nums[i] - mid)) * cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll l = *min_element(nums.begin(), nums.end());
        ll r = *max_element(nums.begin(), nums.end());
        ll result = INT_MAX;
        while (l<=r) {
            ll mid = l + (r-l)/2;
            ll cost1 = check(nums, cost, mid);
            ll cost2 = check(nums, cost, mid+1);
            result = min(cost1, cost2);
            if (cost2 > cost1) {
                r = mid-1;
            }
            else l = mid+1;
        }
        return result == INT_MAX ? 0 : result;
    }
};