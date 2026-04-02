class Solution {
public:
    bool possible(vector<int> &position, int value, int m) {
        int count = 1;
        int prev = position[0];
        for (int i = 1; i<position.size(); i++) {
            int curr = position[i];
            if (curr - prev >= value) {
                prev = curr;
                count++;
            } 
        }
        return count >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int l = 1;
        int r = position[n-1] - position[0];
        int answer = 0;
        while (l<=r) {
            int mid = l+(r-l)/2;
            if (possible(position, mid, m)){
                l = mid+1;
                answer = mid;
            }
            else r = mid-1;
        }
        return answer;
    }
};