class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [] (const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        int currPass = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (auto &trip : trips) {
            int numPass = trip[0], start = trip[1], end = trip[2];
            while (!minHeap.empty() && minHeap.top().first <= start) {
                currPass -= minHeap.top().second;
                minHeap.pop();
            }

            currPass += numPass;
            if (currPass > capacity) return false;
            minHeap.emplace(end,numPass);
        }
        return true;
    }
};