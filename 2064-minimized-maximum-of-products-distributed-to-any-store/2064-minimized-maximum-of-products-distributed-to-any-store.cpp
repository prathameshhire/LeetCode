class Solution {
public:
    bool possible(vector<int> &quantities, int mid, int shops) {
        for (int &product : quantities){
            shops -= (product + mid - 1) / mid;
            if (shops < 0) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int r = *max_element(quantities.begin(), quantities.end());
        int result = 0;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (possible(quantities, mid, n)) {
                r = mid-1;
                result = mid;
            }
            else l = mid+1;
        }
        return result;
    }
};