class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> window;
        int l = 0, len = 0;
        for (int r = 0; r<s.length(); r++) {
            while (window.find(s[r]) != window.end()) {
                window.erase(s[l]);
                l++;
            }

            len = max(len, r-l+1);
            window.insert(s[r]);
        }
        return len;
    }
};