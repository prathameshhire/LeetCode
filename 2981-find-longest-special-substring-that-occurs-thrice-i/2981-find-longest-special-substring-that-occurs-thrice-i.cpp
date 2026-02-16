class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> mp;
        int n = s.length();

        for (int i = 0; i<n; i++) {
            char ch = s[i];
            int l = 0;
            for (int j = i; j<n; j++) {
                if (ch == s[j]) {
                    l++;
                    mp[{ch, l}]++;
                }
                else break;
            }
        }
        int ans = 0;
        for (auto &it : mp) {
            int length = it.first.second;
            int freq = it.second;
            if (freq >= 3) {
                ans = max(ans, length);
            }
        }

        return ans == 0 ? -1 : ans;
    }
};