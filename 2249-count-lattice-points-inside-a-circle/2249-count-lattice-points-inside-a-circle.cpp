class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int ans = 0;
        for (int i = 0; i<=200; i++) {
            for (int j = 0; j<=200; j++) {
                bool flag = false;
                for (int k = 0; k<circles.size(); k++) {
                    int l = ((circles[k][0] - i) * (circles[k][0] - i)) + ((circles[k][1] - j) * (circles[k][1] - j));
                    if (l <= (circles[k][2] * circles[k][2])) {
                        flag = true;
                        break;
                    }
                }
                if (flag) ans++;
            }
        }

        return ans;
    }
};