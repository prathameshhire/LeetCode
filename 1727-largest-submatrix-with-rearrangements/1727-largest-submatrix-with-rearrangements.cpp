class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> preComp(m, vector<int>(n, 0));
        for (int j = 0; j<n; j++) {
            for (int i = 0; i<m; i++) {
                if(matrix[i][j] == 1) {
                    if(i-1 >= 0) preComp[i][j] = 1+preComp[i-1][j];
                    else preComp[i][j] = 1;
                }
                else preComp[i][j] = 0;
            }
        }
        for(int i = 0; i<m; i++) {
            sort(preComp[i].rbegin(), preComp[i].rend());
        }
        int maxArea = 0;
        for (int i = 0; i<m; i++) {
            int minCol = INT_MAX;
            for (int j = 0; j<n; j++) {
                minCol = min(minCol, preComp[i][j]);
                maxArea = max(maxArea, minCol*(j+1));
            }
        }
        return maxArea;
    }
};