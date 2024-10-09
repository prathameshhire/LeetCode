class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int direction = 0;

        vector <int> result;
        int top = 0;
        int down = matrix.size()-1;
        int right = matrix[0].size()-1;
        int left = 0;
        while (top <= down && right >= left) {
            if (direction == 0) {
                for (int i=left; i<=right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;
                direction=1;
                continue;
            }
            if (direction == 1) {
                for (int i=top; i<=down; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
                direction=2;
                continue;
            }
            if (direction == 2) {
                for (int i=right; i>=left; i--){
                    result.push_back(matrix[down][i]);
                }
                down--;
                direction=3;
                continue;
            }
            if (direction == 3) {
                for (int i=down; i>=top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
                direction=0;
                continue;
            }
        }
        return result;
    }
};