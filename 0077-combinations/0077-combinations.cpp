class Solution {
private: 
    void rec (int index, int k, vector<vector<int>> &ans, vector<int> &ds, vector<int>&arr) {
        if (ds.size()==k) {
            ans.push_back(ds);
            return;
        }

        for (int i=index; i<arr.size(); i++ ) {
            ds.push_back(arr[i]);
            rec(i+1,k,ans,ds,arr);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> arr;
        for (int i=1; i<=n; i++) {
            arr.push_back(i);
        }
        rec(0,k,ans,ds,arr);
        return ans;
    }
};