class Solution {
public:
    bool possible(vector<int>&bloomDay, int day, int m, int k) {
        int consecutive = 0;
        for (int x : bloomDay) {
            if (x <= day) {
                consecutive++;
                if (consecutive == k) {
                    m--;
                    consecutive = 0;
                }
            }
            else consecutive = 0;
        }
        return m <= 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 1;
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int result = -1;
        while (l<=r) {
            int mid = l + (r-l)/2;
            if (possible(bloomDay, mid, m, k)) {
                result = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return result;
    }
};