class Solution {
public:
    int binarySearch(vector<vector<int>> &items, int price) {
        int l = 0, r = items.size()-1;
        int maxBeauty = 0;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if (items[mid][0] > price) {
                r = mid-1;
            }
            else{
                l = mid+1;
                maxBeauty = max(maxBeauty, items[mid][1]);
            }
        }
        return maxBeauty;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();
        vector<int> result(m);
        sort(items.begin(), items.end());
        int maxBeauty = items[0][1];
        for (int i = 1; i<n; i++) {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }
        for (int i = 0; i<m; i++) {
            int price = queries[i];
            result[i] = binarySearch(items, price);
        }
        return result;
    }
};