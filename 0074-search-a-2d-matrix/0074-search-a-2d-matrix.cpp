class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bot = matrix.size()-1;
        int col = matrix[0].size()-1;
        while (top<=bot) {
            int row = (top + bot)/2;

            if (target > matrix[row][col]) {
                top = row+1;
            }
            else if (target < matrix[row][0]) {
                bot = row-1;
            }
            else break;
        }

        if (!(top<=bot)) return false;
        
        int row = (top+bot)/2;

        int l = 0;
        int r = col;
        while (l<r) {
            int mid = (l+r)/2;
            if (matrix[row][mid] < target) {
                l = mid+1;
            }
            else if (matrix[row][mid] > target) {
                r = mid-1;
            }
            else return true;
        }

        return false;
    }
};