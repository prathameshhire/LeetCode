class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int i = 0, j = 0;
        int result = 0;
        int count = 0;
        while(j < n) {
            count += abs(s[j] - t[j]);
            while(count > maxCost) {
                count -= abs(s[i] - t[i]);
                i++;
            }
            result = max(result, j-i+1);
            j++;
        }
        return result;
    }
};