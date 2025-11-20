class Solution {
public:
    int execute(vector<int> i, int& fi, int& se) {
        if (fi >= i[0] && se <= i[1]) return 0; 
        if (se >= i[0] && se == i[1]) { fi = i[1] - 1; return 1;}
        if (se >= i[0]) { fi = se; se = i[1]; return 1;}
        fi = i[1] - 1; se = i[1]; return 2;
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1]; 
            });
        int fi = -1, se = -1, res = 0;
        for (auto& i:intervals) {
            res += execute(i, fi, se);
        }
        return res;
    }
};