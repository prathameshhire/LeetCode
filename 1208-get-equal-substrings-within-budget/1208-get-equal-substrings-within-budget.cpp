class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int> nums(n);
        for(int i = 0; i<n; i++) {
            nums[i] = abs(s[i] - t[i]);
        }
        int i = 0, j = 0;
        int result = 0;
        int count = 0;
        while(j < n) {
            count += nums[j];
            while(count > maxCost) {
                count -= nums[i];
                i++;
            }
            result = max(result, j-i+1);
            j++;
        }
        return result;
    }
};