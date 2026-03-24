class Solution {
public:
    int checkHours(vector<int> &piles, int &mid) {
        int ans = 0;
        for (int &p:piles) {
            ans += ceil(1.0 * p/mid);
        } 
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = INT_MIN;
        for (auto &p: piles) {
            r = max(r, p);
        }
        while (l < r) {
            int mid = l + (r-l)/2;
            int hours = checkHours(piles, mid);
            if (h < hours) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return r;
    }
};