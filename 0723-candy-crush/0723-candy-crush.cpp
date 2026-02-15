class Solution {
public:

    void solve(vector<vector<int>> &board) {
        int m = board.size();
        int n = board[0].size();
        bool correct = true;
        
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n-2; j++) {
                int num1 = abs(board[i][j]);
                int num2 = abs(board[i][j+1]);
                int num3 = abs(board[i][j+2]);
                if (num1 != 0 && num1 == num2 && num2 == num3) {
                    board[i][j] = -num1;
                    board[i][j+1] = -num2;
                    board[i][j+2] = -num3;
                    correct = false;
                }
            }
        }

        for (int j = 0; j<n; j++) {
            for (int i = 0; i<m-2; i++) {
                int num1 = abs(board[i][j]);
                int num2 = abs(board[i+1][j]);
                int num3 = abs(board[i+2][j]);
                if (num1 != 0 && num1 == num2 && num2 == num3) {
                    board[i][j] = -num1;
                    board[i+1][j] = -num2;
                    board[i+2][j] = -num3;
                    correct = false;
                }
            }
        }

        for (int j = 0; j<n; j++) {
            int index = m-1;
            for (int i = m-1; i>-1; i--) {
                if (board[i][j] > 0) {
                    board[index][j] = board[i][j];
                    index--;
                }
            }
            for (int r = index; r>-1; r--) {
                board[r][j] = 0;
            }
        }
        if(correct == true) return;
        else{
            solve(board);
        }
    }

    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        solve(board);
        return board;
    }
};