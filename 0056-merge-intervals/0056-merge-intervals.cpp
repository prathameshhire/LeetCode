class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        // Step 1: Sort intervals based on the start times
        sort(intervals.begin(), intervals.end());
        
        // Step 2: Initialize the result vector with the first interval
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        
        // Step 3: Iterate through the intervals and merge overlapping ones
        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& lastInterval = result.back();  // Get the last interval in the result
            vector<int>& currentInterval = intervals[i];
            
            // If the current interval overlaps with the last one in the result
            if (lastInterval[1] >= currentInterval[0]) {
                // Merge by updating the end of the last interval in the result
                lastInterval[1] = max(lastInterval[1], currentInterval[1]);
            } else {
                // Otherwise, there is no overlap, so add the current interval to the result
                result.push_back(currentInterval);
            }
        }
        
        return result;
    }
};
