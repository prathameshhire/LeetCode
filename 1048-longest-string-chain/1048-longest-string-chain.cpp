class Solution {
public:
    int n;

    static bool lambda(string &s1, string &s2) {
        return s1.length() < s2.length();
    }

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

    int longestStrChain(vector<string>& words) {
        n = words.size();
        int maxL = 1;
        sort(words.begin(), words.end(), lambda);
        vector<int> t(n, 1);
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<i; j++) {
                if (isPred(words[j], words[i])) {
                    t[i] = max(t[i], t[j] + 1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        return maxL;
    }

};