class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> mp;
        for (int i = 0; i<s.length(); i++) {
            string curr = "";
            for (int j = i; j<s.length(); j++) {
                if (curr.length() == 0 || curr.back() == s[j]) {
                    curr += s[j];
                    mp[curr]++;
                }
                else break;
            }
        }
        int result = 0;
        for (auto &it : mp) {
            string str = it.first;
            int length = it.second;
            if (length >= 3) {
                int count = str.length();
                result = max(result, count);
            }
        }

        return result == 0 ? -1 : result;
    }
};