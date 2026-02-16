class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        vector<vector<int>> matrix(26, vector<int> (n+1, 0));

        char prev_char = s[0];
        int length = 0;

        for (int i = 0; i<n; i++) {
            char curr_char = s[i];
            if (prev_char == curr_char) {
                length++;
                matrix[curr_char-'a'][length]++;
            }
            else {
                length = 1;
                matrix[curr_char-'a'][length]++;
                prev_char = curr_char;
            }
        }

        int result = -1;

        for (int i = 0; i<26; i++) {
            int cumSum = 0;
            for (int j = n; j>0; j--) {
                cumSum += matrix[i][j];
                if (cumSum >= 3) {
                    result = max(result,j);
                    break; 
                }
            }
        }

        return result;
    }
};