class Solution {
public:
    int n;

    static bool lambda(string &s1, string &s2) {
        return s1.length() < s2.length();
    }

    int t[1001][1001];

    bool isPred(string &prev, string &curr) {
        int M = prev.length();
        int N = curr.length();
        if (M>=N || N-M != 1) return false;
        int i = 0, j = 0;
        while (i < M && j < N) {
            if (prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i == M;
    }

    int lis(vector<string> &words, int prev, int curr) {
        if (curr == n) return 0;

        if (prev != -1 && t[prev][curr] != -1) return t[prev][curr];
        
        int take = 0, skip = 0;
        if (prev == -1 || isPred(words[prev], words[curr])) take = 1 + lis(words, curr, curr+1);
        skip = lis(words, prev, curr+1);
        if (prev != -1) t[prev][curr] = max(take, skip);
        return max(take, skip);
    }

    int longestStrChain(vector<string>& words) {
        memset(t, -1, sizeof(t));
        n = words.size();
        sort(words.begin(), words.end(), lambda);
        return lis(words, -1, 0);
    }

};