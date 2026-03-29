class Solution {
public:
    typedef long long ll;

    bool possible(int len, vector<int> &nums, vector<ll> &prefix, long long k, int n) {
        int i = 0;
        int j = len-1;
        while (j < n) {
            ll target_index = (i + j)/2;
            ll target = nums[target_index];
            ll left_operations = 0;
            ll right_operations = 0;
            if (target_index == 0){
                left_operations = 0;
            }
            else {
                left_operations = abs((target * (target_index-i)) - (prefix[target_index-1] - (i > 0 ? prefix[i-1] : 0)));
            }
            right_operations = abs((prefix[j] - prefix[target_index] - (target * (j-target_index))));
            if (left_operations + right_operations <= k) return true;
            i++;
            j++;
        }
        return false;
    }

    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<ll> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        int l = 1;
        int r = n;
        int result = 1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (possible(mid, nums, prefix, k, n)) {
                result = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return result;
    }
};