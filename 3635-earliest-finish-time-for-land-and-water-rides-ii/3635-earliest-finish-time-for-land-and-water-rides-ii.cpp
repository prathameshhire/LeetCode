class Solution {
public:
    int time(vector<int> &startTime1, vector<int> &duration1, vector<int> &startTime2, vector<int> &duration2) {
        int finish1 = INT_MAX;
        for(int i = 0; i<startTime1.size(); i++) {
            finish1 = min(finish1, startTime1[i] + duration1[i]);
        }
        int finish2 = INT_MAX;
        for(int j = 0; j<startTime2.size(); j++) {
            finish2 = min(finish2, max(startTime2[j], finish1) + duration2[j]);
        }
        return finish2;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landWater = time(landStartTime, landDuration, waterStartTime, waterDuration);
        int waterLand = time(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(landWater, waterLand);        
    }
};