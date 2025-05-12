class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> delta (1001, 0);
        for (auto &trip:trips) {
            int numPass = trip[0], start = trip[1], end = trip[2];
            delta[start] += numPass;
            delta[end] -= numPass;
        }
        int onBoard = 0;
        for (int &s : delta) {
            onBoard += s;
            if (onBoard>capacity) return false;
        }
        return true;
    }
};