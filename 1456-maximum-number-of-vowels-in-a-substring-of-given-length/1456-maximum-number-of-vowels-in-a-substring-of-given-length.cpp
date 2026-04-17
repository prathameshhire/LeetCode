class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int> encode (s.length(), 0);
        for (int i = 0; i<s.length(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u') {
                encode[i] = 1;
            }
        }
        int i = 0, j = 0;
        int result = 0;
        int ans = 0;
        while(j < s.length()) {
            ans += encode[j];
            if(j-i+1 == k) {
                result = max(result, ans);
                ans -= encode[i];
                i++;
            }
            j++;
        }
        return result;
    }
};