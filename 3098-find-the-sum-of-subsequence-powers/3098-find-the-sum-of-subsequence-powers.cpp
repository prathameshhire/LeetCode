class Solution {
public:
int dp[50][50][2], mod = 1000000007;
int dfs(int i, int p, int k, int pwr, bool eq, vector<int>& n) {
    if (k == 0)
        return eq ? pwr : 0;
    if (i >= n.size())
        return 0;
    if (dp[p][k][eq] == -1) {
        dp[p][k][eq] = dfs(i + 1, p, k, pwr, eq, n);
        if (abs(n[i] - n[p]) >= pwr)
            dp[p][k][eq] = (dp[p][k][eq] + dfs(i + 1, i, k - 1, pwr, eq | (n[i] - n[p] == pwr), n)) % mod;
    }
    return dp[p][k][eq];
}
int sumOfPowers(vector<int>& nums, int k) {
    long long res = 0;
    sort(begin(nums), end(nums));
    set<int> pwrs;
    for (int i = 0; i < nums.size(); ++i)
        for (int j = i + 1; j < nums.size(); ++j)
            if (nums[i] != nums[j] && pwrs.insert(nums[j] - nums[i]).second) {
                memset(dp, 255, sizeof(dp));
                res = (res + dfs(0, nums.size() - 1, k, nums[j] - nums[i], false, nums)) % mod;
            }
    return res;
}
};