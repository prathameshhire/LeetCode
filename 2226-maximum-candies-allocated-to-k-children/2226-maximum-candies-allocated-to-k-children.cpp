class Solution {
public:
    bool possible(vector<int> &candies, int mid, long long k) {
        for (int i = 0; i<candies.size(); i++) {
            k -= candies[i]/mid;
        }
        return k <= 0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1;
        int r = *max_element(candies.begin(), candies.end());
        int result = 0;
        long long totalC = 0;
        for (auto &candy : candies) totalC += candy;
        if (totalC < k) return 0;
        while (l<=r) {
            int mid = l+(r-l)/2;
            if (possible(candies, mid, k)) {
                l = mid+1;
                result = mid;
            }
            else r = mid-1;
        }
        return result;
    }
};