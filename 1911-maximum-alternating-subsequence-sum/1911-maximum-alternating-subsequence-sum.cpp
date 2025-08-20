class Solution {
public:
    typedef long long ll;
    int n;
    ll t[100000][2];
    ll solve(int index, vector<int> &nums, bool flag) {
        if (index == n) return 0;
        
        if (t[index][flag] != -1) return t[index][flag];

        ll skip = solve(index+1, nums, flag);
        ll val = nums[index];
        if (!flag) val = -val;
        ll pick = solve(index+1, nums, !flag) + val;
        return t[index][flag] = max(skip, pick);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset (t, -1, sizeof(t));
        return solve(0, nums, true);
    }
};