class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> subset;
        recursion(1, n, res, subset, k);
        return res;
    }
    void recursion(int i, int n, vector<vector<int>> &res, vector<int> &subset, int k) {
        if (subset.size() == k) {
            res.push_back(subset);
            return;
        }
        for (int j = i; j<=n; j++) {
            subset.push_back(j);
            recursion(j+1, n, res, subset, k);
            subset.pop_back();
        }
    }
};