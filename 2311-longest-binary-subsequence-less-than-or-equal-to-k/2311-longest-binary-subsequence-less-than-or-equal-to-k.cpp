class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        long long powerVal = 1;
        int length = 0;
        for (int i = n-1; i>=0; i--) {
            if (s[i] == '0') {
                length++;
            }
            else if(powerVal <= k) {
                length++;
                k-=powerVal;
            }
            if (powerVal <= k) {
                powerVal <<= 1;
            }
        }
        return length;
    }
};