class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        recursion(candidates, target, 0, subset, res, 0);
        return res; 
    }
    void recursion(const vector<int> &candidates, int target, int total, vector<int> &subset, vector<vector<int>> &res, int i) {
        if (total == target) {
            res.push_back(subset);
            return;
        }
        if (total > target || i==candidates.size()) {
            return;
        }
        subset.push_back(candidates[i]);
        recursion(candidates, target, total+candidates[i], subset, res, i);
        subset.pop_back();
        recursion(candidates, target, total, subset, res, i+1);
    }
};