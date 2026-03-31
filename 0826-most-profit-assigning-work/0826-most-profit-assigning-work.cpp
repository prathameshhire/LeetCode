class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();
        vector<pair<int, int>> vec (n);
        for (int i = 0; i<n; i++) {
            vec[i] = {difficulty[i], profit[i]};
        }
        sort(vec.begin(), vec.end());
        sort(worker.begin(), worker.end());
        int totalProfit = 0;
        int j = 0;
        int maxProfit = 0;
        for (int i = 0; i<m; i++) {
            while (j<n && worker[i] >= vec[j].first){
                maxProfit = max(maxProfit, vec[j].second);
                j++;
            }
            totalProfit += maxProfit;
        }
        return totalProfit;
    }
};