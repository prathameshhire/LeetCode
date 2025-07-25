class Solution {
public:
    typedef long long ll;
    ll formula (ll count, ll x) {
        return (count*x) - (count*(count+1))/2; 
    }
    int maxValue(int n, int index, int maxSum) {
        ll left = 1;
        ll mid_val;
        ll right = maxSum;
        int result = 0;
        while (left<=right) {
            mid_val = left + (right-left)/2;
            ll left_count = min ((ll)index, mid_val-1);
            ll left_sum = formula(left_count, mid_val);
            left_sum += max((ll)0, index - (mid_val-1)); 
            ll right_count = min ((ll)n-index-1, mid_val-1);
            ll right_sum = formula(right_count, mid_val);
            right_sum += max((ll)0, n-index-1 - (mid_val-1)); 
            ll total_sum = left_sum + right_sum + mid_val;
            if (total_sum <= maxSum) {
                result = mid_val;
                left = mid_val+1;
            } 
            else {
                right = mid_val-1;
            }
        }
        return result;
    }
};