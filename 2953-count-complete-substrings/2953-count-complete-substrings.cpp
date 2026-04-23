class Solution {
public:
    int solve(int start, int end, string &word, int k) {
        int result = 0;
        for(int unique_char = 1; unique_char <= 26 && unique_char*k <= end-start+1; unique_char++) {
            vector<int> count(26, 0);
            int goodChar = 0;
            int i = start;
            int windowLength = unique_char*k;
            for(int j = i; j<=end; j++) {
                char ch = word[j];
                count[ch-'a']++;
                if(count[ch-'a'] == k) goodChar++;
                else if(count[ch-'a'] == k+1) goodChar--;
                if(j-i+1 > windowLength) {
                    if(count[word[i] - 'a'] == k) goodChar--;
                    else if(count[word[i] - 'a'] == k+1) goodChar++;
                    count[word[i] - 'a']--;
                    i++;
                } 
                if(goodChar == unique_char) result++;
            }
        }
        return result;
    }
    int countCompleteSubstrings(string word, int k) {
        int n = word.size();
        int last = 0;
        int result = 0;
        for(int i = 1; i<=n; i++) {
            if(i == n || abs(word[i] - word[i-1]) > 2) {
                result += solve(last, i-1, word, k);
                last = i;
            }
        }
        return result;
    }
};