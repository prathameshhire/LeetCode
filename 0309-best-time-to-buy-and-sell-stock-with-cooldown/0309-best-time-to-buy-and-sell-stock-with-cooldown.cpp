class Solution {
public:
    int n;
    int t[5001][2];
    int solve(vector<int> &prices, int day, bool buy) {
        if (day >= n) return 0;
        if (t[day][buy] != -1) return t[day][buy];
        int profit = 0;
        if (buy) {
            int take = solve(prices, day+1, false) - prices[day];
            int not_take = solve(prices, day+1, true);
            profit = max({profit, take, not_take});
        }
        else {
            int sell = solve(prices, day+2, true) + prices[day];
            int not_sell = solve(prices, day+1, false);
            profit = max({profit, sell, not_sell});
        }
        return t[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(t, -1, sizeof(t));
        n = prices.size();
        return solve(prices, 0, true);
    }
};