class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int prev = 0;
        int time = 0;
        for (int i = 0; i<colors.size(); i++) {
            if (i > 0 && colors[i] != colors[i-1]) {
                prev = 0;
            }

            int curr = neededTime[i];
            time += min(curr, prev);
            prev = max(prev, curr);
        }

        return time;
    }
};