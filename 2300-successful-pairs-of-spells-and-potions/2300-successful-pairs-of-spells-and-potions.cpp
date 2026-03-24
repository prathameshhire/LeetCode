class Solution {
public:
    int binarySearch(int spell, vector<int> &potions, long long success) {
        int n = potions.size();
        int l = 0;
        int r = potions.size();
        while (l < r) {
            int mid = l + (r-l)/2;
            if (static_cast<long long> (potions[mid]) * spell < success) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        return n-l;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> result(spells.size());
        for (int i = 0; i<spells.size(); i++) {
            result[i] = binarySearch(spells[i], potions, success);
        }
        return result;
    }
};