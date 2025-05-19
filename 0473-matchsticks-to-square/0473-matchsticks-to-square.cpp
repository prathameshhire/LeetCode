class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        vector<int> sides(4,0);
        if (sum%4 != 0) return false;
        int length = sum/4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        return rec(matchsticks, sides, length, 0);
    }

    bool rec(const vector<int> &matchsticks, vector<int> &sides, int length, int index) {
        if (index == matchsticks.size()) return true;
        for (int j = 0; j<4; j++) {
            if (sides[j] + matchsticks[index] <= length) {
                sides[j] += matchsticks[index];
                if (rec(matchsticks, sides, length, index+1)) return true;
                sides[j] -= matchsticks[index];
            }
        }
        return false;
    }
};